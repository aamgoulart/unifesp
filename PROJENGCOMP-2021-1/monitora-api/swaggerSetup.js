swaggerDocument = require("./swagger.json");
const dosesSwagger = require("./swagger-documentation/ibge_doses_swagger");

const createSetupSwagger = () => {
  let setup = {
    ...swaggerDocument,
    host: getCorrectHost(process.env.NODE_ENV),
    definitions: {
      ...dosesSwagger.definition,
    },
    paths: {
      ...dosesSwagger.paths,
    },
  };

  if (process.env.NODE_ENV && process.env.NODE_ENV !== "production") setup.schemes = ["http"];

  return setup;
}

function getCorrectHost(applicationState) {
  return applicationState === "development"
    ? process.env.URL_API_DEVELOPMENT
    : process.env.URL_API_PRODUCTION;
}

module.exports = createSetupSwagger();
