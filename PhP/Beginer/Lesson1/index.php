<!doctype html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Booleans</title>

    <style>
        body {
            display: grid;
            place-items: center;
            height: 100vh;
            margin: 0;
            font-family: sans-serif;
        }

    </style>
</head>
<body>
    <?php
        $name = "1984";
        $read = true;

        if ($read) {
            $message = "You have read $name";
        } else {
            $message = "You have NOT read $name";
        }

    ?>

    <h1>
        <?php echo $message; ?>.
        <?= $message; ?>

    </h1>
</body>
</html>