Module.onRuntimeInitialized = () => {
    console.log(Module._add(3, 5));
};

let fileReader = new FileReader();

function loadFile() {
    let files = document.getElementById('fileInput').files;
    fileReader.addEventListener('loadend', postLoad);
    fileReader.readAsArrayBuffer(files[0]);
}

function postLoad() {
    let arrayBuffer = fileReader.result;
    let byteArray = new Uint8Array(arrayBuffer);
    FS.writeFile('file.txt', byteArray);
    console.log(Module._read());
}
