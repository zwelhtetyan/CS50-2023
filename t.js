const main = () => {
    for (let i = 0; i < 3; i++)
    {
        if (i == 2) return true;
    }

    return false;
}

console.log(main());