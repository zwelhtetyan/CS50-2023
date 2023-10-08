class Student {
  // #id;
  constructor(name, id) {
    // this.#id = id; // let (id) be private
    this.name = name;
    this.id = id;
  }

  // get getID() {
  //   return this.#id;
  // }

  // set changeID(id) {
  //   this.#id = id;
  // }

  changeID(id) {
    this.id = id;
  }

  print() {
    // console.log(`${this.name} is id -> [${this.#id}]`);
    console.log(`${this.name} is ID -> [${this.id}]`);
  }
}

const z = new Student("Zwel", 11);
z.print();
// z.changeID = 111;
z.changeID(111);
z.print();
