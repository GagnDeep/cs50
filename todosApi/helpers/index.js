var db = require('../models/model.js');

exports.getTodos = function(req,res){
    db.Todo.find()
    .then(function(todos){
        res.json(todos);
    })
    .catch(function(error){
        console.log(error);
    })
}

exports.createTodo = function(req,res){
    db.Todo.create(req.body)
    .then(function(newTodo){
        res.json(newTodo);
    })
    .catch(function(error){
        console.log(error);
    })
}

exports.getOne = function(req,res){
    db.Todo.findById(req.params.id)
    .then(function(foundTodo){
        res.json(foundTodo)
    })
    .catch(function(error){
        console.log(error);
    })
}

exports.update = function(req,res){
    db.Todo.findByIdAndUpdate(req.params.id, req.body)
    .then(function(){
        db.Todo.findById(req.params.id)
        .then(function(updatedTodo){
            res.json(updatedTodo)
        })
        .catch(function(error){
            console.log(error)
        })
    })
    .catch(function(error){
            console.log(error)
        })
}

exports.delete = function(req,res){
    db.Todo.findByIdAndRemove(req.params.id)
    .then(function(error){
            res.json({
                message : 'Deleted'
            })
    })
    .catch(function(error){
        console.log(error);
    })
}
module.exports = exports;