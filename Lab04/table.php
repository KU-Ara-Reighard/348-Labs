<html>

<head>
    <h1>
        <div class="stretch">Multiplication Table!</div>
    </h1>
    <link rel="stylesheet" href="stylesheet.css">
</head>

<body>

    <a href="practice4.html" class="button">Go Back!</a><br><br>



    <?php
    $num = (int)$_GET["n"];

    echo "<table>";
    echo "<tr>";
    for ($j = 0; $j < $num + 1; $j++) {
        echo "<th>$j</th>";
    }
    echo "</tr>";

    for ($i = 1; $i < $num + 1; $i++) {
        echo "<tr>";
        echo "<th>$i</th>";
        for ($j = 1; $j < $num + 1; $j++) {
            $product = $i * $j;
            echo "<td>$product</td>";
        }
        echo "</tr>";
    }
    echo "</table>";
    ?>
</body>

</html>