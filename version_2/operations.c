int add(int* arr){
    return arr[1]+arr[0];
}
int minus(int* arr){
    return arr[1]-arr[0];
}
int mult(int* arr){
    return arr[1]*arr[0];
}
int divide(int* arr){
    return arr[1]/arr[0];
}
int uniminus(int* arr){
    return -arr[0];
}

// void calculate(stack *s, char* operator, built_in_word* w, int len)
// {
//     int result;
//     for(int i = 0; i<len; i++)
//     {
//         // which command to execute
//         if(w[i].operator == operator)
//         {
//             int* arr = calloc(w[i].para_count, sizeof(int));
//             // extract parameters
//             for (int j = 0; j < w[i].para_count; j++)
//             {
//                 arr[j] = pop(s);
//             }
//             result = w[i].get_result(arr);
//         }
//     }
//     push(s, result);
// }