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

    // Track Staircase State
    var num_spaces = n - 1;
    var num_hashes = 1;

    // Iteratively Construct/Print Staircase
    for (var row = 0; row < n; row++) {

        // Print Spaces
        for (var i = 0; i < num_spaces; i++)
            process.stdout.write(" ");
        num_spaces--;

        for (var i = 0; i < num_hashes; i++)
            process.stdout.write("#");
        num_hashes++;

        // Advance to Next Row
        process.stdout.write("\n");
    }
}
