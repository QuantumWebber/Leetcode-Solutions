var rand10 = function() {
    while (true) {
        const num = (rand7() - 1) * 7 + rand7();
        if (num <= 40) return (num % 10) + 1;
    }
};