#!/usr/bin/node

const request = require('request');
const filmId = process.argv[2];
const apiUrl = `https://swapi-api.hbtn.io/api/films/${filmId}/`;

/**
 * printCharacters - Prints character names in order
 * @characters: List of character API URLs
 * @index: Current character index
 */
function printCharacters (characters, index) {
  if (index === characters.length) {
    return;
  }

  request(characters[index], (error, response, body) => {
    if (error) {
      return;
    }

    console.log(JSON.parse(body).name);
    printCharacters(characters, index + 1);
  });
}

request(apiUrl, (error, response, body) => {
  if (error) {
    return;
  }

  printCharacters(JSON.parse(body).characters, 0);
});
