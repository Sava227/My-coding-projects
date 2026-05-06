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
            [
                'name' => '1984',
                'author' => 'George Orwell',
                'purchaseUrl' => 'http://example.com'
            ],
            [
                'name' => 'Animal Farm',
                'author' => 'George Orwell',
                'purchaseUrl' => 'http://example.com'
            ]
        ];
    ?>

    <ul>
        <?php foreach ($books as $book) : ?>
            <li>
                <a href="<?= $book['purchaseUrl'] ?>">
                <?= $book['name']; ?>
                </a>
            </li>
        <?php endforeach; ?>
    </ul>
</body>
</html>