
function set_fields(count) {
    var oll = document.getElementById("options05");
    oll.parentNode.removeChild(oll);
    var list = document.createElement("ol");
    list.id = "options05";
    list.type = "1";
    for(let i = 0; i < count; i++){
        var one_input_block = document.createElement("li");
        var input = document.createElement("input");
        input.type = "text";
        input.id = "input_1_" + i;
        input.readOnly = true;
        one_input_block.appendChild(input);
        list.appendChild(one_input_block);
    }
    document.getElementById('options_block5').appendChild(list);
}
