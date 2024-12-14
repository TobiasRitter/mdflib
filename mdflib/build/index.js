const fileReader = new FileReader();

function loadFile() {
    const files = document.getElementById('fileInput').files;
    fileReader.addEventListener('loadend', postLoad);
    fileReader.readAsArrayBuffer(files[0]);
}

function postLoad() {
    const data = new Uint8Array(fileReader.result);
    FS.writeFile('Test.mf4', data);
    console.log(Module._mf4read());
}
