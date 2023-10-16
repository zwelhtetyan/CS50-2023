const multiple_choice_questions = [
  {
    question: "How many rivers are in Saudi Arabia?",
    answers: [
      {answer: 1, correct: false},
      {answer: 0, correct: true},
      {answer: 2, correct: false},
      {answer: 3, correct: false},
    ]
  },
  {
    question: `Who is the author of the series "Malazan Book of the Fallen"?`,
    answers: [
      {answer: "Ian Cameron Esslemont", correct: false},
      {answer: "Steven Erikson", correct: true},
      {answer: "George R. R. Martin", correct: false},
      {answer: "J. R. R. Tolkien", correct: false},
    ]
  },
  {
    question: "Which of these car models are produced by Lamborghini?",
    answers: [
      {answer: "Huayra", correct: false},
      {answer: "Aventador", correct: true},
      {answer: "Chiron", correct: false},
      {answer: "918", correct: false},
    ]
  },
]

const free_response_questions = [
  {
    question: "Who create c programming language?",
    answer: "Dennis Ritchie"
  },
  {
    question: "What does HTML stand for short answer?",
    answer: "Hypertext Markup Language"
  },
  {
    question: `Which programming language use "console.log()" to print something as output.`,
    answer: "Javascript"
  }

]

function main() {
  const part1_q = document.querySelector(".part_1 > .question");
  const choice_btn_container = document.querySelector(".choice_btn_container");
  const part_1_noti_alert = document.querySelector(".part_1 > .noti_alert")
  const part2_q = document.querySelector(".part_2 > .question");

  const random_multiple_choice_question = shuffle(multiple_choice_questions)[0];

  part1_q.innerText = random_multiple_choice_question.question;

  // insert answer btn to dom and check answer
  shuffle(random_multiple_choice_question.answers).forEach(answer_item => {
    const btn = document.createElement("button");
    btn.classList.add("multiple_choice_btn")
    btn.innerText = answer_item.answer;

    // check answer logic
    btn.addEventListener('click', () => {
      if (answer_item.correct) {
        btn.style.background = '#58ff58';
        part_1_noti_alert.innerText = "Correct!"
      }else {
        btn.style.background = 'red';
        part_1_noti_alert.innerText = "Incorrect!"
      }

      document.querySelectorAll(".multiple_choice_btn").forEach(btn => {
        btn.disabled = true;
      })
    })

    choice_btn_container.appendChild(btn);
  })



}

function shuffle(arr) {
  let currentIdx = arr.length,  randomIdx;

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