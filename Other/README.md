# TechSoC 2026

[![Level](https://img.shields.io/badge/Level-Beginner%20to%20Advanced-2ea44f?style=flat-square)](#)
[![Language](https://img.shields.io/badge/Language-Any-0d6efd?style=flat-square)](#)
[![Format](https://img.shields.io/badge/Format-Self--Paced-9c27b0?style=flat-square)](#)
[![Elimination](https://img.shields.io/badge/Elimination-None-ff6f00?style=flat-square)](#)

*A beginner-friendly coding challenge organized by students at IIT Indore.*

---

## About TechSoC

TechSoC is how a lot of us at IIT Indore actually learned to code — not through a lecture, but by getting handed a problem that was just slightly out of reach and figuring it out. This year's version keeps that spirit: a handful of problem statements, released roughly every **10–12 days**, each one starting easy and getting harder as you go.

There's no cutoff round. Nobody gets eliminated for submitting a rough solution. The only way to not move forward is to not submit anything at all.

If you've never written a line of code, you can still do this. If you've been competitive programming for two years, there's enough in the later levels to keep you interested too.

---

## What Makes This Special

### Progressive Difficulty
Each problem statement has **three levels** baked in — so within one PS alone you're going from *"get this working"* to *"now make it good."*

- **Level 1:** Basic concepts everyone can grasp
- **Level 2:** Build confidence with increasing complexity
- **Level 3:** Advanced challenges for those who want more

### Bonus Levels
Complete the main challenges early? We've got **bonus levels** that will push your skills even further and keep the excitement going.

### Student-Led Learning
This event is crafted by fellow students who understand exactly what you need to succeed in competitive programming and club selections.

### No Elimination Policy
- Everyone who submits functioning code can proceed
- Even partial solutions with clear effort are valued
- Learning effort matters more than perfect solutions

> *"This is about learning and growth, not elimination. Give it your best shot."*

---

## Resources

Stuck on a concept? Don't worry. Check out our comprehensive [Resources Guide](RESOURCES.md) featuring:
- Interactive coding tutorials & video courses
- Reference materials for quick lookups
- Websites for those who learn by reading
- Community-recommended learning paths
- Git & GitHub guides if that's what's tripping you up

*The goal isn't to know everything upfront — it's to learn how to learn.*

---

## How to Participate

### Step 1 — Fork the Repository

1. Create a **GitHub account** if you don't already have one
2. Click the **"Fork"** button at the top-right of this repository
3. Select your GitHub account as the destination
4. Wait for the fork to complete

### Step 2 — Clone Your Fork

```bash
# Clone your forked repository
git clone https://github.com/<your-username>/TechSoC-26.git

# Navigate to the project directory
cd TechSoC-26

# Add the original repository as upstream (for updates)
git remote add upstream https://github.com/godofwar1007/TechSoC-26.git

# Verify your remotes
git remote -v
```

> If none of that made sense yet, that's fine — there's a walkthrough in [RESOURCES.md](RESOURCES.md).

---

### Directory Structure

Once problem statements start dropping, your fork should look like this:

```
TechSoC-26/
├── README.md                          # Main challenge information
├── RESOURCES.md                       # Learning resources
├── Problem_Statement_1/
│   ├── README.md                      # Problem description
│   ├── your_solution.py/.cpp/...      # Your solution (any language)
│   ├── test_cases/                    # Test files (if any)
│   └── documentation.md               # Your approach explanation
```

---

### Submission Guidelines

**What to include in each problem folder:**
- Your working solution in your preferred language
- `documentation.md` explaining your approach (optional but recommended)
- Comments in your code explaining key logic
- Test cases you created (if any)

### Keeping Your Fork Updated

```bash
# Fetch updates from the original repository
git fetch upstream

# Merge updates into your main branch
git checkout main
git merge upstream/main

# Push updates to your fork
git push origin main
```

### Submitting Your Work

```bash
# Add your changes
git add .

# Commit with a descriptive message
git commit -m "Added solution for PS 1"

# Push to your fork
git push origin main
```

We'll send out a short **Google Form** asking for your repo link once a problem statement closes — that's how we know to go check out your work. Make sure everything's pushed before then.

---

## Evaluation & Progression

### What We Evaluate

**Primary Criteria:**
- Functioning code that solves the problem correctly
- Clear understanding of the concepts involved
- Genuine effort and problem-solving approach

**Bonus Points:**
- Good documentation explaining your thought process
- Clean, readable code with proper comments
- Additional test cases or edge case handling
- Creative optimizations or alternative approaches

### About Bonus Levels

- Not required for progression to the next PS
- Great for skill building and deeper understanding
- Show your enthusiasm for learning
- Available for early finishers who want to keep going instead of waiting around

---

## What You'll Achieve

By completing this challenge, you'll build:

### Core Programming Skills
- Variables, loops, and conditional logic
- Functions and modular programming
- Data structures and algorithms
- Object-oriented programming concepts

### Problem-Solving Mindset
- Breaking complex problems into manageable pieces
- Debugging and testing strategies
- Code optimization and efficiency
- Handling edge cases and error conditions

### Competition Readiness
- Algorithmic thinking
- Clean, readable code structure
- Time management in coding challenges
- Confidence to tackle unknown problems

---

## For Everyone, At Every Level

| **Complete Beginners** | **Some Experience** |
|---|---|
| Never written a line of code? Perfect. Start with Level 1 of each PS and watch your skills grow day by day. | Already know the basics? Jump into Level 2 and Level 3 and discover new concepts that will expand your programming knowledge. |

---

## A Note on Working Together

Talking through problems with other participants is completely fine — encouraged, even. Debug together, argue about approaches, share what confused you. But **write your own code**. This is one of the few times you'll get to solve something entirely on your own before you're thrown into club teams where you're relying on other people's code too. Use it.

---

## Frequently Asked Questions

<details>
<summary><strong>I've genuinely never coded before — can I still do this?</strong></summary>
<br>
<strong>Absolutely.</strong> Level 1 of each problem statement is built with complete beginners in mind. Start there, and use the resources guide alongside it — you're not expected to already know anything walking in. Check out our <a href="RESOURCES.md">Resources Guide</a> to get started.
</details>

<details>
<summary><strong>Does it matter which language I use?</strong></summary>
<br>
Not really. <strong>Python</strong> or <strong>C++</strong> are what we'd recommend since most of the resources point that way, but if you're more comfortable in Java, JavaScript, or something else, go for it. We're evaluating your problem-solving, not your syntax choice.
</details>

<details>
<summary><strong>How much time should I be putting into this per day?</strong></summary>
<br>
There's no fixed requirement, but as a rough guide:
<ul>
<li><strong>Beginners:</strong> 2–3 hours per day (including time spent learning)</li>
<li><strong>Some Experience:</strong> 1–2 hours per day</li>
</ul>
Going slower and actually understanding it beats rushing through.
</details>

<details>
<summary><strong>What if I fall behind or start late?</strong></summary>
<br>
Every problem statement stays open the whole time, so there's no penalty for catching up later. Go at whatever pace makes sense for you.
</details>

<details>
<summary><strong>Can I work with a partner or submit as a team?</strong></summary>
<br>
<strong>No — solo submissions only.</strong>
<br><br>
<strong>Why individual submissions?</strong>
<ul>
<li>In clubs, you'll always work in teams — this is your chance to learn individually</li>
<li>Personal skill building — write every line of code yourself</li>
<li>Individual confidence — know that YOU can solve problems</li>
<li>Your own pace — learn without depending on others' schedules</li>
</ul>
<br>
<strong>Discussion is still encouraged:</strong>
<ul>
<li>Talk through concepts with fellow participants</li>
<li>Share debugging strategies and problem-solving approaches</li>
<li>Exchange learning resources and helpful tutorials</li>
<li>Brainstorm different approaches to the same problem</li>
</ul>
</details>

<details>
<summary><strong>What do I actually need to participate?</strong></summary>
<br>
Just the basics — all free, all easy to set up:
<ul>
<li>A laptop with internet access</li>
<li>A text editor or IDE (VS Code works fine)</li>
<li>A compiler or interpreter for your chosen language</li>
<li>Git for version control</li>
</ul>
</details>

<details>
<summary><strong>How do I know if my solution is actually correct?</strong></summary>
<br>
Each PS folder comes with:
<ul>
<li>Example inputs and outputs</li>
<li>A description of expected behavior</li>
</ul>
Write a few of your own test cases too — it's good practice and it'll catch edge cases the examples don't cover. We'll also give feedback once evaluations are done.
</details>

<details>
<summary><strong>Are there prizes?</strong></summary>
<br>
Not in the traditional sense — the real outcome here is:
<ul>
<li>Confidence to tackle any coding problem</li>
<li>A portfolio of solved problems you built yourself</li>
<li>Strong problem-solving skills</li>
<li>Readiness for club selections and competitions</li>
</ul>
The real reward is becoming a better programmer.
</details>

<details>
<summary><strong>I finished early — now what?</strong></summary>
<br>
A few options:
<ul>
<li>Tackle the bonus level for that PS</li>
<li>Optimize what you already built</li>
<li>Try solving it in a different programming language</li>
<li>Help someone else who's stuck</li>
</ul>
Whatever keeps you engaged until the next release.
</details>

---

<div align="center">

### Crafted by Students, For Students

Built by students at IIT Indore who figured most of this out by getting stuck and asking around — hoping this makes that process a little less lonely for you.

---

**Made with care by the TechSoC 2026 Team**

⭐ Star this repo if you find it helpful.

</div>
