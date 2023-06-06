function solution(n, control) {
    return control.split("").reduce((a,element)=>{
        if(element==="w"){
            return(a+1);
        }
        if(element==="s"){
            return a-1;
        }
        if(element==="d"){
            return a+=10;
        }
        if(element==="a"){
            return a-=10;
        }
    },n);
}