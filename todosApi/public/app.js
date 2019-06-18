$(document).ready(function(){

    $.getJSON('/api/todos')
    .then(function(data){
        addTodos(data);
    })
    $('input').keypress(function(event){
        if(event.which == 13){
            var text = $('input').val();
            createTodo(text);
            $('input').val('');
        }
    })
    $('.list').on('click','span',function(event){
        event.stopPropagation();
        removeTodo($(this).parent());
    })
    $('.list').on('click','li',function(){
        $(this).toggleClass('done');
        updateTodo($(this));
    })

})
function addTodos(data){
    data.forEach(function(todo){
        addTodo(todo)
    })
}

function addTodo(todo){
    var newTodo = $('<li class = "task">'+ todo.name+'<span>X</span></li>');
    newTodo.data('id',todo._id);
    newTodo.data('completed',todo.completed);
    if(todo.completed){
        newTodo.addClass('done');
    }
    $('.list').append(newTodo);
}

function createTodo(text){
    $.post('/api/todos',{name : text})
    .then(function(newTodo){
        addTodo(newTodo);
    })
    .catch(function(error){
        console.log(error);
    })
}
function removeTodo(element){
    $.ajax({
        method : 'delete',
        url : '/api/todos/'+element.data('id')
    })
    .then(function(message){
        element.remove();
    })
}

function updateTodo(element){
    var isDone = element.data('completed')
    var updatedData = {
        completed : !isDone
    }
    $.ajax({
        method : 'put',
        url : '/api/todos/' + element.data('id'),
        data : updatedData
    })
    .then(function(todo){
        element.data('completed',!isDone);
    })
}