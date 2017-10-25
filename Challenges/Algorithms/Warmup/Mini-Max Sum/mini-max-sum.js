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
    arr = readLine().split(' ');
    arr = arr.map(Number);

    var sum_min = 0;
    var sum_max = 0;
    arr.sort();
    for (var i = 0; i < arr.length - 1; i++) {
        sum_min += arr[i];
        sum_max += arr[i+1];
    }

    console.log(sum_min + " " + sum_max);
}
