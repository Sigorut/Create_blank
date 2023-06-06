function create_fields_for_num(id_ex) {
    const main_div = document.createElement("div");
    main_div.id = "id_" + id_ex;
    const pbody_div = document.createElement("div");
    pbody_div.className = "pbody";
    const p_text_ex = document.createElement("p");
    p_text_ex.innerHTML += "<b>Задание:</b>";
    const text_ex = document.createElement("p");
    text_ex.id = "text_" + id_ex;
    text_ex.readOnly = true;
    p_text_ex.appendChild(text_ex);
    const p_image = document.createElement("p");
    p_image.id = "image_" + id_ex;
    const p_text_answer = document.createElement("p");
    p_text_answer.innerHTML = "<b>Ответ:</b>";
    const p_answer = document.createElement("p");
    p_answer.id = "answer_" + id_ex;
    pbody_div.appendChild(p_text_ex);
    pbody_div.appendChild(p_image);
    pbody_div.appendChild(p_text_answer);
    pbody_div.appendChild(p_answer);
    const solution = document.createElement("div");
    const p_text_solution = document.createElement("p");
    p_text_solution.innerHTML = "Пояснение:";
    const p_solution = document.createElement("p");
    p_solution.id = "solution_" + id_ex;
    solution.appendChild(p_text_solution);
    solution.appendChild(p_solution);

    main_div.appendChild(pbody_div);
    main_div.appendChild(solution);
    const block = document.getElementById("num");
    block.appendChild(main_div);
}

function create_fields_for_comp(id_ex, count_options){
    const main_div = document.createElement("div");
    main_div.id = "id_" + id_ex;
    const pbody_div = document.createElement("div");
    pbody_div.className = "pbody";
    const p_text_ex = document.createElement("p");
    p_text_ex.innerHTML += "<b>Задание:</b>";
    const text_ex = document.createElement("p");
    text_ex.id = "text_" + id_ex;
    text_ex.readOnly = true;
    p_text_ex.appendChild(text_ex);
    const list_A = document.createElement("ol");
    list_A.type = "A";
    const list_1 = document.createElement("ol");
    list_1.type = "1";
    for(let i = 0; i < count_options; i++){
        const one_li_on_list_A = document.createElement("li");
        const one_p_on_list_A = document.createElement("p");
        one_p_on_list_A.id = "list_A_" + id_ex + "_" + i;
        one_li_on_list_A.appendChild(one_p_on_list_A);
        list_A.appendChild(one_li_on_list_A);
    }
    for(let j = 0; j < count_options; j++){
        const one_li_on_list_1 = document.createElement("li");
        const one_p_on_list_1 = document.createElement("p");
        one_p_on_list_1.id = "list_1_" + id_ex + "_" + j;
        one_li_on_list_1.appendChild(one_p_on_list_1);
        list_1.appendChild(one_li_on_list_1);
    }

    const p_image = document.createElement("p");
    p_image.id = "image_" + id_ex;
    const p_text_answer = document.createElement("p");
    p_text_answer.innerHTML = "<b>Ответ:</b>";
    pbody_div.appendChild(p_text_ex);
    pbody_div.appendChild(p_image);
    pbody_div.appendChild(p_text_answer);
    pbody_div.appendChild(list_A);
    pbody_div.appendChild(list_1);
    const solution = document.createElement("div");
    const p_text_solution = document.createElement("p");
    p_text_solution.innerHTML = "Пояснение:";
    const p_solution = document.createElement("p");
    p_solution.id = "solution_" + id_ex;
    solution.appendChild(p_text_solution);
    solution.appendChild(p_solution);

    main_div.appendChild(pbody_div);
    main_div.appendChild(solution);
    const block = document.getElementById("num");
    block.appendChild(main_div);
}

function create_fields_for_seq(id_ex, count_options){
    const main_div = document.createElement("div");
    main_div.id = "id_" + id_ex;
    const pbody_div = document.createElement("div");
    pbody_div.className = "pbody";
    const p_text_ex = document.createElement("p");
    p_text_ex.innerHTML += "<b>Задание:</b>";
    const text_ex = document.createElement("p");
    text_ex.id = "text_" + id_ex;
    text_ex.readOnly = true;
    p_text_ex.appendChild(text_ex);
    const list_1 = document.createElement("ol");
    list_1.type = "1";
    for(let j = 0; j < count_options; j++){
        const one_li_on_list_1 = document.createElement("li");
        const one_p_on_list_1 = document.createElement("p");
        one_p_on_list_1.id = "list_1_" + id_ex + "_" + j;
        one_li_on_list_1.appendChild(one_p_on_list_1);
        list_1.appendChild(one_li_on_list_1);
    }

    const p_image = document.createElement("p");
    p_image.id = "image_" + id_ex;
    const p_text_answer = document.createElement("p");
    const p_answer = document.createElement("p");
    p_answer.id = "answer_" + id_ex;
    p_text_answer.innerHTML = "<b>Ответ:</b>";
    pbody_div.appendChild(p_text_ex);
    pbody_div.appendChild(p_image);
    pbody_div.appendChild(list_1);
    pbody_div.appendChild(p_text_answer);
    pbody_div.appendChild(p_answer);
    const solution = document.createElement("div");
    const p_text_solution = document.createElement("p");
    p_text_solution.innerHTML = "Пояснение:";
    const p_solution = document.createElement("p");
    p_solution.id = "solution_" + id_ex;
    solution.appendChild(p_text_solution);
    solution.appendChild(p_solution);

    main_div.appendChild(pbody_div);
    main_div.appendChild(solution);
    const block = document.getElementById("num");
    block.appendChild(main_div);
}

function create_fields_for_table_word(id_ex, count_rows, count_cols){
    const main_div = document.createElement("div");
    main_div.id = "id_" + id_ex;
    const pbody_div = document.createElement("div");
    pbody_div.className = "pbody";
    const p_text_ex = document.createElement("p");
    p_text_ex.innerHTML += "<b>Задание:</b>";
    const text_ex = document.createElement("p");
    text_ex.id = "text_" + id_ex;
    text_ex.readOnly = true;
    p_text_ex.appendChild(text_ex);
    const p_image = document.createElement("p");
    p_image.id = "image_" + id_ex;

    const body_table = document.createElement("tbody");
    for(let i = 0; i < count_rows; i++){
        let one_row_block = document.createElement("tr");
        for(let j = 0; j < count_cols; j++){
            let p_on_table = document.createElement("p");
            let one_col_table = document.createElement("td");
            p_on_table.id = "table_" + id_ex + "_" + i + "_" + j;
            p_on_table.className = "table_field";
            one_col_table.appendChild(p_on_table);
            one_row_block.appendChild(one_col_table);
        }
        body_table.appendChild(one_row_block);
    }

    const p_text_answer = document.createElement("p");
    const p_answer = document.createElement("p");
    p_answer.id = "answer_" + id_ex;
    p_text_answer.innerHTML = "<b>Ответ:</b>";
    pbody_div.appendChild(p_text_ex);
    pbody_div.appendChild(p_image);
    pbody_div.appendChild(body_table);
    pbody_div.appendChild(p_text_answer);
    pbody_div.appendChild(p_answer);
    const solution = document.createElement("div");
    const p_text_solution = document.createElement("p");
    p_text_solution.innerHTML = "Пояснение:";
    const p_solution = document.createElement("p");
    p_solution.id = "solution_" + id_ex;
    solution.appendChild(p_text_solution);
    solution.appendChild(p_solution);

    main_div.appendChild(pbody_div);
    main_div.appendChild(solution);
    const block = document.getElementById("num");
    block.appendChild(main_div);
}

function create_fields_for_threetf(id_ex, count_options){
    const main_div = document.createElement("div");
    main_div.id = "id_" + id_ex;
    const pbody_div = document.createElement("div");
    pbody_div.className = "pbody";
    const p_text_ex = document.createElement("p");
    p_text_ex.innerHTML += "<b>Задание:</b>";
    const text_ex = document.createElement("p");
    text_ex.id = "text_" + id_ex;
    text_ex.readOnly = true;
    p_text_ex.appendChild(text_ex);
    const p_image = document.createElement("p");
    p_image.id = "image_" + id_ex;

    const list_1 = document.createElement("ol");
    list_1.type = "1";
    for(let i = 0; i < count_options; i++){
        let one_li_on_list_1 = document.createElement("li");
        let one_p_on_list_1 = document.createElement("input");
        one_p_on_list_1.id = "list_1_" + id_ex + "_" + i;
        one_p_on_list_1.type = "text";
        one_p_on_list_1.readOnly = true;
        one_p_on_list_1.className = "field";
        var checkbox = document.createElement("input");
        checkbox.type = "checkbox";
        checkbox.id = "checkbox_" + id_ex + "_" + i;
        checkbox.disabled = true;
        one_li_on_list_1.appendChild(checkbox);
        one_li_on_list_1.appendChild(one_p_on_list_1);
        list_1.appendChild(one_li_on_list_1);
    }

    pbody_div.appendChild(p_text_ex);
    pbody_div.appendChild(p_image);
    pbody_div.appendChild(list_1);
    const solution = document.createElement("div");
    const p_text_solution = document.createElement("p");
    p_text_solution.innerHTML = "Пояснение:";
    const p_solution = document.createElement("p");
    p_solution.id = "solution_" + id_ex;
    solution.appendChild(p_text_solution);
    solution.appendChild(p_solution);

    main_div.appendChild(pbody_div);
    main_div.appendChild(solution);
    const block = document.getElementById("num");
    block.appendChild(main_div);
}


function delete_ex(id_ex) {
    var ex = document.getElementById("id_" + id_ex);
    ex.parentNode.removeChild(ex);

}
