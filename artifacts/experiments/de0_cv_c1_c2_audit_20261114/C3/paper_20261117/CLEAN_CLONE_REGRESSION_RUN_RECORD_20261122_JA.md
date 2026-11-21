# 公開branch clean-clone native regression記録（2026-11-22）

## 対象と再現条件

- Repository: `https://github.com/Unjuno/resource-conditioned-neural-computation.git`
- Branch: `codex/c3v2-paper-evidence-20261117`
- Clone HEAD: `6e07b86b9cc0a9384ba88177e06ec5afb34b218b`
- Cloneは既存作業ツリーとは別の空きディレクトリへ新規取得した。初期状態は対象branchを追跡し、未変更。
- Host: Windows 11、WSL Ubuntu 24.04
- Verilator: `5.020 2024-01-01 rev (Debian 5.020-1)`
- Ibex: `lowRISC/ibex` commit `7b5df75a041affe56e8c235260f98a09b3319008`（リポジトリ外の固定checkout）
- SOF書込み、JTAG、DE0-CV実機操作は行っていない。

## 実行

fresh clone内の `C3/paper_20261117` で、追跡済み `prepare_native_regression.py` を実行した。スクリプトは凍結source listとmanifestを検査し、146件の各SHA-256を確認してから新しいrun directoryを作成する。次にそのrun directoryで `bash ./verify_and_run.sh` を実行した。

```sh
python3 prepare_native_regression.py \
  --repo-root <fresh-clone-root> \
  --ibex-root /opt/rtnn-tools/ibex \
  --output-dir source_recovery_20261122/native_regression_verified_clone_run1
cd source_recovery_20261122/native_regression_verified_clone_run1
bash ./verify_and_run.sh
```

## 結果

| 検査 | 結果 |
|---|---|
| frozen source graph | PASS、146/146 hash一致（141 pinned Ibex + 5 archived project variants） |
| source-presence check | PASS、exit 0 |
| native 42-request regression compile/run | PASS、compile/run exit 0 |
| request outcomes | PASS、42 scheduled cases + 2 reset-recovery replay records |
| negative cases | PASS、集約結果にbad CRC、duplicate、busy reset、payload CRC、unknown input/model/build |
| response-write guard | PASS、partial write拒否、full commit許可、empty再commit拒否 |
| overall runner | PASS、exit 0 |

`run_v2_42.log` には44件の `C2_SOC_CASE_PASS`、6件の個別 `C2_SOC_NEGATIVE_PASS` と7種の負例を列挙した総括行がある。負例名 `busy_reset` は総括に含まれる。生成ログは `native_regression_verified_clone_run1/` に保存した。`obj_v2_*` のビルドキャッシュは証拠コピーには含めず、実行したclone内に残した。

## warningと解釈の範囲

Verilatorのwarningは抑制されていない完全無警告ビルドではない。保存したcompile logには42要求側138件、guard側139件があり、両方に `BLKSEQ` 4、`DECLFILENAME` 1、`PINCONNECTEMPTY` 80、`UNUSEDPARAM` 48、`UNUSEDSIGNAL` がそれぞれ3/6件、42要求側のみ `SYNCASYNCNET` 2件を含む。runnerは `-Wno-fatal` を使うため、終了コード0はwarning-freeを意味しない。

この記録が確認するのは、指定public branch snapshot、明示source map、固定Ibex checkout、保存されたnative testbenchの組合せでのsource hashとVerilator回帰である。Quartus Fitter/STA、SOF/ELFの再生成同一性、JTAG外部タイミング、CDCの物理的保証、実機測定、WCETを証明しない。B-SIGNOFFは引き続きBLOCKED、C3 v2 KEY0 replayはPENDING_OPERATOR、full campaignはNOT_RUN。
