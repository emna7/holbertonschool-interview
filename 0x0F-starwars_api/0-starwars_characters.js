#!/usr/bin/node

const request = require('request');
const url = 'https://swapi-api.hbtn.io/api/films/' + process.argv[2];

try {
  request(url, async function (error, response, body) {
    if (error) {
      console.log(error);
    } else {
      const characters = JSON.parse(body).characters;
      for (const character of characters) {
        const resp = await new Promise((resolve, reject) => {
          request(character, (erro, resp, html) => {
            if (erro) {
              reject(erro);
            } else {
              resolve(JSON.parse(html).name);
            }
          });
        });
        console.log(resp);
      }
    }
  });
} catch (error) {
  console.log(error);
}
