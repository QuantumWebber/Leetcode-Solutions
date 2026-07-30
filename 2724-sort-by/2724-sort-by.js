/**
 * @param {Array} arr
 * @param {Function} fn
 * @return {Array}
 */
var sortBy = function(arr, fn) {
    return arr.slice().sort((a, b) => {
        const aValue = fn(a);
        const bValue = fn(b);
        if (aValue < bValue) return -1;
        if (aValue > bValue) return 1;
        return 0;
    });
};

// Example usage:
const arr = [1, 2, 3, 4, 5];
const fn = x => -x; // Sorting in descending order
console.log(sortBy(arr, fn)); // Output: [5, 4, 3, 2, 1]
