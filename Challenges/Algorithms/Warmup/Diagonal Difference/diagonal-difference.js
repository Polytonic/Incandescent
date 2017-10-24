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
    var a = [];
    for(a_i = 0; a_i < n; a_i++){
       a[a_i] = readLine().split(' ');
       a[a_i] = a[a_i].map(Number);
    }

    // Matrix State Variables
    var sum_diagonal_primary = 0;
    var sum_diagonal_secondary = 0;
    var current_column_primary = 0;
    var current_column_secondary = n - 1;

    for (var row_index = 0; row_index < n; row_index++) {
        for (var column_index = 0; column_index < n; column_index++) {

            // Check the Primary Diagonal
            if (column_index == current_column_primary)
                sum_diagonal_primary += a[row_index][column_index];

            // Check the Secondary Diagonal
            if (column_index == current_column_secondary)
                sum_diagonal_secondary += a[row_index][column_index];
        }

        // Advance to the Next Row
        current_column_primary += 1;
        current_column_secondary -= 1;
    }

    console.log(Math.abs(sum_diagonal_primary - sum_column_secondary));
}
