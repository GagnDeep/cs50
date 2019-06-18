// validation script here
const validation = {
    telephone: /^\d{11}$/,
    username:/^[a-z0-9]{5,12}$/i,
    password:/^[\w@\-]{8,20}$/,
    slug:/^[a-z0-9\-]{8,20}$/,
    email:/^([a-z\d\.\-\\]+)@([a-z\d\.\\\-]+)\.([a-z]{2,8})(\.[a-z]{2,8})?$/i,
}

let inputs = Array.from(document.querySelectorAll('input'))
inputs.forEach(input=>input.addEventListener('keyup',validate));

function validate(e){
    let regex = validation[e.target.attributes.name.value];
    if(regex.test(e.target.value)){
       e.target.className = 'valid' ;
       console.log('t')
    }else{
        e.target.className = 'invalid';
        console.log('f')
    }}
