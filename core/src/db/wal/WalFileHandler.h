// Licensed to the Apache Software Foundation (ASF) under one
// or more contributor license agreements.  See the NOTICE file
// distributed with this work for additional information
// regarding copyright ownership.  The ASF licenses this file
// to you under the Apache License, Version 2.0 (the
// "License"); you may not use this file except in compliance
// with the License.  You may obtain a copy of the License at
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing,
// software distributed under the License is distributed on an
// "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied.  See the License for the
// specific language governing permissions and limitations
// under the License.

#pragma once

#include <string>
#include "WalDefinations.h"

namespace milvus {
namespace engine {
namespace wal {

class MXLogFileHandler {
 public:
    MXLogFileHandler();
    MXLogFileHandler(const std::string& mxlog_path);
    ~MXLogFileHandler();

    bool IsOpen();
    std::string GetFilePath();
    std::string GetFileName();
    bool OpenFile();
    bool CloseFile();
    bool Load(char *buf);
    bool Write(char *buf, const uint64_t& data_size, bool is_sync = false);
    void ReBorn(const uint64_t& new_file_no);
    uint64_t GetFileSize();
    void SetFileOpenMode(const std::string& open_mode);
    void SetFilePath(const std::string& file_path);
    void SetFileName(const std::string& file_name);
    void DeleteFile();
    bool FileExists();

 private:
    std::string file_path_;
    std::string file_name_;
    std::string file_mode_;
    uint64_t file_size_;
    FILE* p_file_;
};

} // wal
} // engine
} // milvus

