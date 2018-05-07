// var ws = new WebSocket('ws://192.168.0.1:8080/');
var ws = new WebSocket('ws://localhost:8080/');
console.log("WebSocket connection opened!")

ws.onopen = function() {
};

ws.onclose = function() {
};

ws.onmessage = function(event) {
    if (event.data.slice(0, 1) == 1) {
        document.getElementById('Kp-value-read').textContent = (event.data).slice(1);
    }
    if (event.data.slice(0, 1) == 2) {
        document.getElementById('Ki-value-read').textContent = (event.data).slice(1);
    }
    if (event.data.slice(0, 1) == 3) {
        document.getElementById('Kd-value-read').textContent = (event.data).slice(1);
    }
}

function send() {
    if (document.getElementById('Kp').value != '') {
        ws.send('1' + (document.getElementById('Kp').value));
        document.getElementById('Kp').value = '';
    }
    if (document.getElementById('Ki').value != '') {
        ws.send('2' + (document.getElementById('Ki').value));
        document.getElementById('Ki').value = '';
    }
    if (document.getElementById('Kd').value != '') {
        ws.send('3' + (document.getElementById('Kd').value));
        document.getElementById('Kd').value = '';
    }
}

function exit() {
    console.log("WebSocket connection closed!")
    ws.close();
}