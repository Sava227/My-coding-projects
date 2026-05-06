<!doctype html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Arrays</title>
</head>
<body>
    <h1>Recommended books</h1>

    <?php
        $books = [
            "1984",
            "Animal Farm",
            "Do Androids Dream of Electric Sheep"
        ];
    ?>

    <ul>
        <?php foreach ($books as $book) : ?>
            <li><?php echo $book; ?></li>
        <?php endforeach; ?>
    </ul>
</body>
</html>