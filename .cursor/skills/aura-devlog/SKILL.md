---
name: aura-devlog
description: 为 Aura GAS 课程学习项目管理笔记与上下文恢复。当用户说「继续学习 aura」「继续学课程」时，自动读取最新笔记恢复上下文；当用户说「记录一下」「形成文档」「总结本节」时，写入课程笔记；当用户说「提交」时，同时提交笔记 repo 和代码 repo。
---

# Aura GAS 课程学习日志

## 路径速查

| 用途 | 路径 |
|---|---|
| **我的代码 repo** | `C:\Users\clintzhou\Desktop\git_repos\GAS_Aura_Learning` |
| **课程参考 repo** | `C:\Users\clintzhou\Desktop\git_repos\GameplayAbilitySystem_Aura` |
| **笔记目录** | `C:\Users\clintzhou\Desktop\git_repos\dev_sandbox\UE_course_notes` |

代码 repo 在 `follow-along` 分支；参考 repo 是课程作者的工程，只读对照，不要在里面改东西。

## 恢复上下文

用户说「继续学 Aura」时，**先做这个**，不要直接问「学到哪了」：

1. Glob `C:\Users\clintzhou\Desktop\git_repos\dev_sandbox\UE_course_notes\*.md`，按文件名排序取最新的。
2. Read 最新的 1-2 篇笔记。
3. 用两三句话说明上次停在哪一集、留了什么未解决的问题，然后再问这次要做什么。

同时值得看一眼代码 repo 的 `git status`：未提交的改动往往就是上次做到一半的地方，比笔记更新。

## 笔记命名

```
YYMMDD_E[起]-E[止]_topic-in-kebab-case.md
```

实际例子：

- `260527-29_E033-E045_delegates-GE-stacking-clamping.md`
- `260608_E063-E081_clamp-repnotify-mmc-combat-interface.md`

跨多天的连续学习用 `260527-29` 这种日期区间；集数用区间而非单集，因为一次记录通常覆盖多集。

## 内容要求

笔记是给三个月后的自己看的，不是课程字幕的复述：

- **课程进度**：这批覆盖哪些集、对应工程里哪个功能。
- **概念辨析**：UE/GAS 里容易混的成对概念，例如 PreAttributeChange vs PostGameplayEffectExecute 各自在什么时机、能改什么。
- **踩坑与报错**：原始报错信息、真实原因、怎么定位的。这部分最值钱，不要省。
- **代码与资产改动**：动了哪些文件、为什么这么改。

## 笔记模板

```markdown
# E[X]-E[Y]: 本批主题

**日期**: YYYY-MM-DD
**项目**: UE5 GAS Top-Down RPG
**集数**: E[X]-E[Y]
**一句话**: 本批笔记的概括

---

## 1. 本批内容与要点

按集推进 + 每集的「为什么这么做」。

## 2. 概念辨析

成对概念、调用时机、常见误用。

## 3. 代码与资产改动

| 文件 | 改动 |
|---|---|
| `XXX.h/.cpp` | ... |
```

## 「提交」的含义

用户说「提交」= **两个 repo 各自 commit 并 push 到 GitHub**，不要只提交一个。

### 1. 笔记 repo（dev_sandbox）

```
C:\Users\clintzhou\Desktop\git_repos\dev_sandbox
```

提交本次新增或修改的笔记，然后 `git push`。

### 2. 代码 repo（GAS_Aura_Learning）

```
C:\Users\clintzhou\Desktop\git_repos\GAS_Aura_Learning
```

提交本次的源码与资产改动，然后 `git push`（当前分支 `follow-along`）。

先跑 `git status` 和 `git diff` 看清两个 repo 各自改了什么，再分别写 commit message，逐个 commit 并 push。commit message 用课程集数开头，和历史记录保持一致，例如 `E082-E094: native gameplay tags, attribute info data asset, attribute menu UI`。

不要提交 IDE 本地文件：`Aura.uproject.DotSettings.user`（Rider 个人设置）。`.uasset` 是二进制，改动无法在 diff 里核对，提交前先确认是本次确实动过的资产。
