Module.onRuntimeInitialized = () => {
    console.log(Module._add(3, 5));
  };
  
  const fileInput = document.getElementById('fileInput');
  const processButton = document.getElementById('processButton');
  const output = document.getElementById('output');

  processButton.addEventListener('click', async () => {
      const file = fileInput.files[0];
      if (!file) {
          output.textContent = 'Please select a file first.';
          return;
      }

      // Read the file content
      const fileContent = await file.arrayBuffer();
      output.textContent = `File read`;
  });
