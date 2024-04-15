
let binarySearch = (array, target)=>{
    let start = 0;
    let end = array.length - 1;
    let mid = start + Math.floor((end - start)/2);

    while(start <= end){
        if(array[mid] == target){
            return mid;
        }else if(target > array[mid]){
            start = mid + 1;
        }else{
            end = mid - 1;
        }
        mid = start + Math.floor((end - start)/2);
    }
    return "Not found";
}


const arr = [1,3,5,6,8,9,10,15,20];
const target = 100;

const result = binarySearch(arr,target);
console.log(result);