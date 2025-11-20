#!/usr/bin/env node
"use strict";

// Read and parse input
function inputReadfn() {
  const fs = require("fs");
  const actualinput = fs.readFileSync(0, "utf8");
  const tokenn = actualinput.trim().split(/\s+/);
  let posi = 0;
  const totalrowsgrid = parseInt(tokenn[posi++], 10);
  const totalcolsgrid = parseInt(tokenn[posi++], 10);
  const city = [];
  for (let i = 0; i < totalrowsgrid; ++i) city.push(tokenn[posi++]);
  const storemovement = tokenn[posi++] || "";
  return { totalrowsgrid, totalcolsgrid, city, storemovement };
}

// Check if cell is valid and open
function checkvalid(row, col, totalrowsgrid, totalcolsgrid, city) {
  return row >= 0 && row < totalrowsgrid && col >= 0 && col < totalcolsgrid && city[row][col] === ".";
}

// Handle left and right turns
function leftturntaken(dir) { return (dir + 3) % 4; }
function rightturntaken(dir) { return (dir + 1) % 4; }

// Simulate movement from a starting position
function trackallmoment(startRow, startCol, startDir, storemovement, city, totalrowsgrid, totalcolsgrid) {
  const dRow = [-1, 0, 1, 0], dCol = [0, 1, 0, -1];
  let r = startRow, c = startCol, d = startDir;
  for (let i = 0; i < storemovement.length; ++i) {
    const ch = storemovement[i];
    if (ch === "L") d = leftturntaken(d);
    else if (ch === "R") d = rightturntaken(d);
    else { r += dRow[d]; c += dCol[d]; if (!checkvalid(r, c, totalrowsgrid, totalcolsgrid, city)) return { ok: false }; }
  }
  return { ok: true, r, c };
}

// Try all starting points and count valid endings
function finaldetective() {
  const { totalrowsgrid, totalcolsgrid, city, storemovement } = inputReadfn();
  const finishSet = new Set();
  for (let row0 = 0; row0 < totalrowsgrid; ++row0) {
    for (let col0 = 0; col0 < totalcolsgrid; ++col0) {
      if (city[row0][col0] !== ".") continue;
      for (let dir0 = 0; dir0 < 4; ++dir0) {
        const finalans = trackallmoment(row0, col0, dir0, storemovement, city, totalrowsgrid, totalcolsgrid);
        if (finalans.ok) finishSet.add(`${finalans.r},${finalans.c}`);
      }
    }
  }
  console.log(finishSet.size === 0 ? "Impossible" : finishSet.size);
}

// Run program
finaldetective();
