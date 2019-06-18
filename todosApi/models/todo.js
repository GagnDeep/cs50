var mongoose = require('mongoose');

var todoSchema = new mongoose.Schema({
    name : {
        type : String,
        required : 'Name cannot be empty'
    },
    completed : {
        type : Boolean,
        default : false
    },
    date : {
        type : Date,
        default : Date.now()
    }
})

module.exports = mongoose.model('Todo',todoSchema);