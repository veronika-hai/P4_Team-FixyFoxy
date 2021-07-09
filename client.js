fetch("http://localhost:3000")
  .then((response) => {
      response.json().then((json) => {
          console.log(json);
          document.getElementById("placeholder").src = json.ImageDir;
      }).catch((err) => {
        console.warn("Something went wrong.", err);
      });
  })
  .catch((err) => {
    console.warn("Something went wrong.", err);
  });

