process.stdin.resume();
process.stdin.setEncoding('ascii');

var input_stdin = "";
var input_stdin_array = "";
var input_currentline = 0;

process.stdin.on('data', function (data) {
    input_stdin += data;
});

process.stdin.on('end', function () {
    input_stdin_array = input_stdin.split("\n");
    main();
});

function readLine() {
    return input_stdin_array[input_currentline++];
}

/////////////// ignore above this line ////////////////////

function main() {
    var n = parseInt(readLine());
    arr = readLine().split(' ');
    arr = arr.map(Number);

    var positives = 0;
    var negatives = 0;
    var zeroes = 0;

    for (var i = 0; i < arr.length; i++) {
        if (arr[i] < 0)
            negatives += 1;
        else if (arr[i] > 0)
            positives += 1;
        else if (arr[i] == 0)
            zeroes += 1;
    }

    console.log((positives / n).toPrecision(6));
    console.log((negatives / n).toPrecision(6));
    console.log((zeroes / n).toPrecision(6));
}
