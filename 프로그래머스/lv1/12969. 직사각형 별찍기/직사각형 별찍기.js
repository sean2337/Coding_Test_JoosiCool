process.stdin.setEncoding('utf8');
process.stdin.on('data', data => {
    const n = data.split(" ");
    const a = Number(n[0]), b = Number(n[1]);
    var star ="";
    for(var k = 0;k<a;k++){
            star+="*";
    }
    for(var i = 0;i<b;i++){
        console.log(star);
    }
    
    
});