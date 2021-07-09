const sqlite3 = require("sqlite3");
const express = require("express");
const cors = require("cors");

const server = express();

server.use(express.json());
server.use(cors());

server.get("/", (req, res) => {
    const db = new sqlite3.Database("image.db");
    const query = "SELECT ImageDir FROM images WHERE Knocksign=110";
    db.each(query,
        (err, row) => {
          if (err) {
            console.error("Etwas ist schief gegangen", err);
            return;
          }
    
          console.log(row);
          res.send(row);
        }
      );
      db.close();
      
    });

  server.listen("3000");