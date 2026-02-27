#!/usr/bin/python3
"""Read stdin logs and compute metrics."""

import re
import sys


VALID_CODES = [200, 301, 400, 401, 403, 404, 405, 500]
LINE_RE = re.compile(
    r'^\S+ - \[.*\] "GET /projects/260 HTTP/1\.1" (\d+) (\d+)$'
)


def print_stats(total_size, counts):
    """Print current metrics."""
    print("File size: {}".format(total_size))
    for code in VALID_CODES:
        if counts[code] > 0:
            print("{}: {}".format(code, counts[code]))


def parse_line(line):
    """Parse one log line and return status code and file size."""
    match = LINE_RE.match(line.strip())

    if match is None:
        return (None, None)

    try:
        status = int(match.group(1))
        size = int(match.group(2))
    except (TypeError, ValueError):
        return (None, None)

    return (status, size)


def main():
    """Run log parsing on stdin."""
    total_size = 0
    line_count = 0
    counts = {code: 0 for code in VALID_CODES}

    try:
        for line in sys.stdin:
            line_count += 1

            status, size = parse_line(line)
            if status is not None and size is not None:
                total_size += size
                if status in counts:
                    counts[status] += 1

            if line_count % 10 == 0:
                print_stats(total_size, counts)
    except KeyboardInterrupt:
        print_stats(total_size, counts)
        return

    if line_count == 0 or line_count % 10 != 0:
        print_stats(total_size, counts)


if __name__ == "__main__":
    main()
