function set_fields(count) {
    var oll = document.getElementById("options04");
    oll.parentNode.removeChild(oll);
    var list = document.createElement("ol");
    list.id = "options04";
    list.type = "1";
    for(let i = 0; i < count; i++){
        var one_input_block = document.createElement("li");
        var input = document.createElement("input");
        input.type = "text";
        input.id = "input_text_" + i;
        input.readOnly = true;

        var checkboxx = document.createElement("input");
        checkboxx.type = "checkbox";
        checkboxx.id = "checkbox_input_" + i;
        checkboxx.disabled = true;
        one_input_block.appendChild(checkboxx);
        one_input_block.appendChild(input);
        list.appendChild(one_input_block);
    }
    document.getElementById('options_block4').appendChild(list);
}
