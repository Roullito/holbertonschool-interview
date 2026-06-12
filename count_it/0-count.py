#!/usr/bin/python3
"""Count keywords in hot Reddit post titles."""

import requests


def print_counts(counts):
    """Print non-zero keyword counts sorted by count and name."""
    sorted_counts = sorted(counts.items(),
                           key=lambda item: (-item[1], item[0]))

    for word, count in sorted_counts:
        if count > 0:
            print("{}: {}".format(word, count))


def count_words(subreddit, word_list, after=None, counts=None, keywords=None):
    """Recursively query Reddit and count keyword occurrences."""
    if counts is None or keywords is None:
        counts = {}
        keywords = {}
        for word in word_list:
            word = word.lower()
            keywords[word] = keywords.get(word, 0) + 1
            counts[word] = 0

    if not keywords:
        return

    url = "https://www.reddit.com/r/{}/hot.json".format(subreddit)
    headers = {
        "User-Agent": "python:holberton.count_it:v1.0.0 (by /u/holberton)"
    }
    params = {"limit": 100}

    if after is not None:
        params["after"] = after

    try:
        response = requests.get(url, headers=headers, params=params,
                                allow_redirects=False)
        if response.status_code != 200:
            return
        data = response.json().get("data")
    except (requests.RequestException, ValueError):
        return

    if data is None:
        return

    for child in data.get("children", []):
        title = child.get("data", {}).get("title", "")
        for word in title.lower().split():
            if word in keywords:
                counts[word] += keywords[word]

    after = data.get("after")
    if after is None:
        print_counts(counts)
        return

    count_words(subreddit, word_list, after, counts, keywords)
