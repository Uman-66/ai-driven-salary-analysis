# 🧠 Data Science Salary Analysis Project

## 📘 Overview

This project explores **global data science salaries** by combining multiple datasets to analyze how factors like experience level, company size, remote work, and cost of living affect salaries worldwide. The dataset is enriched with GDP and cost-of-living data to enable deeper economic insights.

The project follows a structured pipeline approach with **four main phases** (so far completed: Phase 0 to Phase 3).

---

## 🏗️ Phase 0 — Project Setup

**Objective:** Initialize the environment and organize the project.

### Steps:

1. **Created folder structure:**

   ```
   data/
     raw/
     cleaned/
     processed/
   notebooks/
   scripts/
   ```
2. Installed dependencies: `pandas`, `numpy`, `matplotlib`, `seaborn`, `pathlib`, and others.
3. Verified environment and Python interpreter (fixed environment issues when needed).

---

## 🧩 Phase 1 — Data Loading & Inspection

**Objective:** Load all datasets, inspect structure, and identify potential cleaning needs.

### Datasets Used:

* **Data Science Salaries Dataset (2024)** — Kaggle dataset with global salary data.
* **GDP Data (1973–2024)** — Annual GDP per country.
* **Cost of Living Dataset (2024)** — Cost of living, rent, and purchasing power indices.

### Steps:

1. Imported all datasets using `pandas.read_csv()`.
2. Inspected basic structure:

   ```python
   df.info()
   df.describe()
   df.head()
   ```
3. Checked for nulls, duplicates, and inconsistent column names.
4. Ensured correct data types for numerical and categorical columns.

### Outcome:

All three datasets successfully loaded and verified. Ready for cleaning.

---

## 🧹 Phase 2 — Data Cleaning & Integration

**Objective:** Clean, merge, and prepare the data for analysis.

### Steps:

1. **Renamed and standardized columns** for readability (e.g., `salary_in_usd`, `work_year`, `experience_level`).
2. **Mapped codes to readable text:**

   ```python
   exp_map = {'EN': 'Entry', 'MI': 'Mid', 'SE': 'Senior', 'EX': 'Executive'}
   cleaned['experience_level'] = cleaned['experience_level'].map(exp_map)
   ```
3. **Handled duplicates and missing values.**
4. **Merged datasets:**

   * Combined salary dataset with GDP and Cost of Living datasets by country.
5. **Reindexed the dataframe** to use the numerical count column as the index.
6. Added derived fields like `log_salary` for better normalization.

### Outcome:

A unified, clean dataset containing columns:

```
['Country', 'work_year', 'experience_level', 'employment_type',
 'job_title', 'salary_in_usd', 'remote_ratio', 'company_size',
 'Cost of Living Index', 'Rent Index', 'Local Purchasing Power Index',
 'Cost of Living Plus Rent Index', 'GDP', 'remote_type', 'log_salary']
```

Exported as → `data/cleaned/cleaned_salary_data.csv`

---

## ⚙️ Phase 3 — Feature Engineering

**Objective:** Create new meaningful features and prepare data for modeling.

### Steps:

1. **Created directory** for processed data:

   ```python
   from pathlib import Path
   Path('data/processed').mkdir(parents=True, exist_ok=True)
   ```
2. **Added/engineered new features:**

   * `log_salary` → log-transformed salary for normalization.
   * `remote_type` → categorized based on `remote_ratio`.
3. **Prepared final dataset** for modeling with encoded and numeric values (to be done in Phase 4).
4. **Exported datasets:**

   ```python
   cleaned.to_csv('data/processed/engineered_salary_data.csv', index=False)
   # df_final.to_csv('data/processed/model_ready_salary_data.csv', index=False)
   ```
5. Verified export success and structure.

### Outcome:

Data successfully transformed and saved for modeling.

---

## 🚀 Next Steps (Phase 4)

**Goal:** Model training and evaluation.

* Encode categorical variables.
* Split data into training and testing sets.
* Build predictive models (e.g., Linear Regression, Random Forest).
* Evaluate with RMSE, R², and visualizations.

---

## 📁 Folder Summary

```
project_root/
├── data/
│   ├── raw/                  # Original datasets
│   ├── cleaned/              # Cleaned merged data
│   └── processed/            # Feature-engineered data
├── notebooks/                # Jupyter notebooks per phase
├── scripts/                  # Python scripts for automation
└── README.md                 # Documentation
```

---

## ✅ Current Progress Summary

| Phase | Status  | Description                              |
| ----- | ------- | ---------------------------------------- |
| 0     | ✅ Done  | Environment setup and structure creation |
| 1     | ✅ Done  | Data loading and inspection              |
| 2     | ✅ Done  | Data cleaning and integration            |
| 3     | ✅ Done  | Feature engineering and export           |
| 4     | 🔜 Next | Modeling and evaluation                  |

---

## 📦 Outputs So Far

* **Cleaned Dataset:** `data/cleaned/cleaned_salary_data.csv`
* **Processed Dataset:** `data/processed/engineered_salary_data.csv`

---

## 🧭 Notes

* Keep Jupyter notebooks versioned per phase.
* Use Git commits after completing each phase.
* Maintain consistent naming conventions for all exports.

---

*End of Phase 3 — Data Prepared for Modeling.*
