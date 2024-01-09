const search = (arr, callback) => {
    const result = [];
    for(const e of arr){
        if(callback(e))
            result.push(e);
    }
    return result;
}
