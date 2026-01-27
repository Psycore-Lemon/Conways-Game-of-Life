# Test Plan
**Project:** Conway’s Game of Life  
**Author:** Fergus Miller  
**Date:** 2025  
**Version:** 1.0

---

## 1. Introduction

### 1.1 Purpose
This document defines the testing strategy and test activities for the Conway’s Game of Life implementation. The purpose of this test plan is to verify correctness of the game rules, ensure rendering consistency, and evaluate performance and robustness under varying simulation sizes.

### 1.2 Scope
This test plan covers:
- Simulation logic implementing the Game of Life rules
- Rendering of the grid using OpenGL
- Performance under normal and stress conditions

Out of scope:
- User interface usability evaluation

---

## 2. Test Objectives

- Verify correct implementation of the four Game of Life rules
- Maintain at least a performance of 30fps
- Detect invalid data and runtime errors early

---

## 3. Test Strategy

### 3.1 Test Levels

| Level | Description |
|------|------------|
| Unit Testing | Individual functions implementing rule logic |
| Integration Testing | Interaction between simulation and rendering |
| System Testing | Verify that the full application runs correctly with OpenGL rendering and ImGui UI components integrated
| Stress Testing | Large grid sizes and long runtimes |

---

### 3.2 Test Types

- Functional testing
- Boundary and edge-case testing
- Stress and performance testing
- Regression testing

---

## 5. Test Cases

### 5.1 Unit Tests

| ID | Description | Expected Outcome |
|----|------------|------------------|
| UT-01 | Alive cell with <2 neighbours | Cell dies |
| UT-02 | Alive cell with 2–3 neighbours | Cell lives |
| UT-03 | Dead cell with 3 neighbours | Cell becomes alive |
| UT-04 | Alive cell with >3 neighbours | Cell dies |

---

### 5.2 Integration Tests

| ID | Description | Expected Outcome |
|----|------------|------------------|
| IT-01 | Update grid then render | Display matches internal state |
| IT-02 | Resize grid | No rendering artefacts |

---

### 5.3 System Tests

OpenGl comes with in built tests to tell us if something goes wrong, this will help us determin errors that are related to OpenGl

---

### 5.4 Stress Tests

| ID | Description | Expected Outcome |
|----|------------|------------------|
| PT-01 | Grid 1000×1000 | Acceptable frame rate |
| PT-02 | Long runtime simulation | No crashes or memory leaks |

---

## 6. Instrumentation and Monitoring

- Assertions for grid invariants
- Logging of generation count and timing
- File-based performance logs during stress tests

---

## 7. Entry and Exit Criteria

### Entry Criteria
- Code compiles successfully
- Required test environment available

### Exit Criteria
- All critical test cases pass
- No unresolved assertion failures
- Performance remains within acceptable limits

---

