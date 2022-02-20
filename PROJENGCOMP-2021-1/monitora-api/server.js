require('dotenv/config');
require("./app/models");

const express = require("express");
const bodyParser = require("body-parser");
const cors = require("cors");

// const swaggerUi = require("swagger-ui-express");
// const swaggerSetup = require("./swaggerSetup");

const app = express();

app.use(cors());

// parse requests of content-type - application/json
app.use(bodyParser.json());

// parse requests of content-type - application/x-www-form-urlencoded
app.use(bodyParser.urlencoded({ extended: true }));

// simple route
app.get("/", (req, res) => {
  res.json({ message: "Welcome to application." });
});


require("./app/routes/cases.routes")(app);
require("./app/routes/vaccination.routes")(app);
require("./app/routes/covid.routes")(app);

// app.use(
//   '/api-docs',
//   swaggerUi.serve, 
//   swaggerUi.setup(swaggerSetup)
// );

// set port, listen for requests
const PORT = process.env.PORT || 8080;
app.listen(PORT, () => {
  console.log(`Server is running on port ${PORT}.`);
});