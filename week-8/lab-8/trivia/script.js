const multiple_choice_questions = [
  {
    question: "How many rivers are in Saudi Arabia?",
    answers: [
      { answer: 1, correct: false },
      { answer: 0, correct: true },
      { answer: 2, correct: false },
      { answer: 3, correct: false },
    ],
  },
  {
    question: `Who is the author of the series "Malazan Book of the Fallen"?`,
    answers: [
      { answer: "Ian Cameron Esslemont", correct: false },
      { answer: "Steven Erikson", correct: true },
      { answer: "George R. R. Martin", correct: false },
      { answer: "J. R. R. Tolkien", correct: false },
    ],
  },
  {
    question: "Which of these car models are produced by Lamborghini?",
    answers: [
      { answer: "Huayra", correct: false },
      { answer: "Aventador", correct: true },
      { answer: "Chiron", correct: false },
      { answer: "918", correct: false },
    ],
  },
];

const free_response_questions = [
  {
    question: "Who create c programming language?",
    answer: "Dennis Ritchie",
  },
  {
    question: "What does HTML stand for short answer?",
    answer: "Hypertext Markup Language",
  },
  {
    question: `Which programming language use "console.log()" to print something as output?`,
    answer: "Javascript",
  },
];

function main() {
  const part1_q = document.querySelector(".part_1 > .question");
  const part2_q = document.querySelector(".part_2 > .question");
  const choice_btn_container = document.querySelector(".choice_btn_container");
  const part_1_noti_alert = document.querySelector(".part_1 > .noti_alert");
  const part_2_noti_alert = document.querySelector(".part_2 > .noti_alert");
  const free_response_form = document.querySelector(".free_response_form");

  const random_multiple_choice_question = shuffle(multiple_choice_questions)[0];

  //insert question to part_1
  part1_q.innerText = random_multiple_choice_question.question;

  // insert answer btn to dom and check answer
  shuffle(random_multiple_choice_question.answers).forEach((answer_item) => {
    const btn = document.createElement("button");
    btn.classList.add("multiple_choice_btn");
    btn.innerText = answer_item.answer;

    // check answer logic
    btn.addEventListener("click", () => {
      if (answer_item.correct) {
        btn.style.background = "#58ff58";
        part_1_noti_alert.innerText = "Correct!";
      } else {
        btn.style.background = "red";
        part_1_noti_alert.innerText = "Incorrect!";
      }

      document.querySelectorAll(".multiple_choice_btn").forEach((btn) => {
        btn.disabled = true;
      });
    });

    choice_btn_container.appendChild(btn);
  });

  const free_response_question = shuffle(free_response_questions)[0];

  //insert question to part_2
  part2_q.innerText = free_response_question.question;

  free_response_form.addEventListener("submit", (e) => {
    e.preventDefault();

    const formData = new FormData(e.target);

    const answer = formData.get("answer");

    if (!answer.trim()) return;

    if (
      answer.toLocaleLowerCase() ===
      free_response_question.answer.toLocaleLowerCase()
    ) {
      e.target.answer.style.borderColor = "#58ff58";
      part_2_noti_alert.innerText = "Correct!";
    } else {
      e.target.answer.style.borderColor = "red";
      part_2_noti_alert.innerText = "Incorrect!";
    }

    e.target.answer.disabled = true;
    e.target.submit_btn.disabled = true;
  });
}

function shuffle(arr) {
  let currentIdx = arr.length,
    randomIdx;

  // While there remain elements to shuffle.
  while (currentIdx > 0) {
    // Pick a remaining element.
    randomIdx = Math.floor(Math.random() * currentIdx);
    currentIdx--;

    // And swap it with the current element.
    [arr[currentIdx], arr[randomIdx]] = [arr[randomIdx], arr[currentIdx]];
  }

  return arr;
}

document.addEventListener("DOMContentLoaded", main);
