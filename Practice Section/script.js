function linearSearch(arr,target){
    for(let i=0;i<=arr.length;i++){
        if(arr[i] === target){
            return true;
        }
    }
    return false;
}


function swap(array, index1, index2) {
    let temp = array[index1];
    array[index1] = array[index2];
    array[index2] = temp;
}

function swapAlternatives(array) {
    for (let i = 0; i < array.length; i += 2) {
        if (i + 1 < array.length) {
            swap(array, i, i + 1); // Pass array and indices
        }
    }
}

let array = [1, 2, 3, 5, 6, 7];
swapAlternatives(array);
console.log(array); // Output: [2, 1, 5, 3, 7, 6]



// console.log(linearSearch(array,target))