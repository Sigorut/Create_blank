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

}

function delete_ex(id_ex) {
    var ex = document.getElementById("id_" + id_ex);
    ex.parentNode.removeChild(ex);

}
