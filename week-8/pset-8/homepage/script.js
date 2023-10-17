const works = [
  {
    title: "Dev.to-clone",
    desc: "Social blog platform for developers.",
    preview_url: "https://dev-community-clone.vercel.app/",
    img_url:
      "https://www.zwelhtetyan.com/_next/image?url=%2Fimages%2Fdev.to-clone.png&w=640&q=75",
  },
  {
    title: "Tiktok-clone",
    desc: "Social video sharing web app.",
    preview_url: "https://tiktok-clone-zhy.vercel.app/",
    img_url:
      "https://www.zwelhtetyan.com/_next/image?url=%2Fimages%2Ftiktok-clone.png&w=640&q=75",
  },
  {
    title: "Z-shop",
    desc: "Mini e-commerce website",
    preview_url: "https://shopify-olive.vercel.app/",
    img_url:
      "https://www.zwelhtetyan.com/_next/image?url=%2Fimages%2Fshopify.png&w=640&q=75",
  },
  {
    title: "Realtor",
    desc: "Real estate website",
    preview_url: "https://realtor-zhy.vercel.app/",
    img_url:
      "https://www.zwelhtetyan.com/_next/image?url=%2Fimages%2Frealtor.png&w=640&q=75",
  },
];

function main() {
  const workContainer = document.querySelector(".work_container");
  const loveCs50 = document.querySelector(".love_cs50");

  works.forEach((work) => {
    const card = document.createElement("div");
    card.classList.add("card");

    card.innerHTML = `
      <img
      src=${work.img_url}
      class="card-img-top"
      alt=${work.title}
      />
      <div class="card-body">
        <h5 class="card-title fs-5">${work.title}</h5>
        <p class="card-text">${work.desc}</p>
      </div>
    `;

    card.addEventListener("click", () => {
      window.open(`${work.preview_url}`, "_blank").focus();
    });

    workContainer.appendChild(card);
  });

  function blinkText() {
    const hide = loveCs50.classList.contains("blink");

    if (hide) {
      loveCs50.classList.remove("blink");
    } else {
      loveCs50.classList.add("blink");
    }
  }

  setInterval(blinkText, 300);
}

document.addEventListener("DOMContentLoaded", main);
