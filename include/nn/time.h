/**
 * @file time.h
 * @brief Time implementation.
 */

#pragma once

#include <nn/types.h>

namespace nn {

struct TimeSpanType {
public:
    s64 _ns;

public:
    static constexpr TimeSpanType FromNanoSeconds(s64 ns) { return { ns }; }
    static constexpr TimeSpanType FromMicroSeconds(s64 ms)
    {
        return FromNanoSeconds(ms * INT64_C(1000));
    }
    static constexpr TimeSpanType FromMilliSeconds(s64 ms)
    {
        return FromMicroSeconds(ms * INT64_C(1000));
    }
    static constexpr TimeSpanType FromSeconds(s64 s) { return FromMilliSeconds(s * INT64_C(1000)); }
    static constexpr TimeSpanType FromMinutes(s64 m) { return FromSeconds(m * INT64_C(60)); }
    static constexpr TimeSpanType FromHours(s64 h) { return FromMinutes(h * INT64_C(60)); }
    static constexpr TimeSpanType FromDays(s64 d) { return FromHours(d * INT64_C(24)); }

    constexpr s64 GetNanoSeconds() const { return _ns; }
    constexpr s64 GetMicroSeconds() const { return this->GetNanoSeconds() / (INT64_C(1000)); }
    constexpr s64 GetMilliSeconds() const
    {
        return this->GetNanoSeconds() / (INT64_C(1000) * INT64_C(1000));
    }
    constexpr s64 GetSeconds() const
    {
        return this->GetNanoSeconds() / (INT64_C(1000) * INT64_C(1000) * INT64_C(1000));
    }
    constexpr s64 GetMinutes() const
    {
        return this->GetNanoSeconds() / (INT64_C(1000) * INT64_C(1000) * INT64_C(1000) * INT64_C(60));
    }
    constexpr s64 GetHours() const
    {
        return this->GetNanoSeconds() / (INT64_C(1000) * INT64_C(1000) * INT64_C(1000) * INT64_C(60) * INT64_C(60));
    }
    constexpr s64 GetDays() const
    {
        return this->GetNanoSeconds() / (INT64_C(1000) * INT64_C(1000) * INT64_C(1000) * INT64_C(60) * INT64_C(60) * INT64_C(24));
    }

    constexpr friend bool operator==(const TimeSpanType& lhs, const TimeSpanType& rhs)
    {
        return lhs._ns == rhs._ns;
    }
    constexpr friend bool operator!=(const TimeSpanType& lhs, const TimeSpanType& rhs)
    {
        return lhs._ns != rhs._ns;
    }
    constexpr friend bool operator<=(const TimeSpanType& lhs, const TimeSpanType& rhs)
    {
        return lhs._ns <= rhs._ns;
    }
    constexpr friend bool operator>=(const TimeSpanType& lhs, const TimeSpanType& rhs)
    {
        return lhs._ns >= rhs._ns;
    }
    constexpr friend bool operator<(const TimeSpanType& lhs, const TimeSpanType& rhs)
    {
        return lhs._ns < rhs._ns;
    }
    constexpr friend bool operator>(const TimeSpanType& lhs, const TimeSpanType& rhs)
    {
        return lhs._ns > rhs._ns;
    }

    constexpr TimeSpanType& operator+=(const TimeSpanType& rhs)
    {
        _ns += rhs._ns;
        return *this;
    }
    constexpr TimeSpanType& operator-=(const TimeSpanType& rhs)
    {
        _ns -= rhs._ns;
        return *this;
    }

    constexpr friend TimeSpanType operator+(const TimeSpanType& lhs, const TimeSpanType& rhs)
    {
        TimeSpanType r(lhs);
        return r += rhs;
    }
    constexpr friend TimeSpanType operator-(const TimeSpanType& lhs, const TimeSpanType& rhs)
    {
        TimeSpanType r(lhs);
        return r -= rhs;
    }
};

class TimeSpan {

private:
    TimeSpanType m_ts;

public:
    constexpr TimeSpan(const TimeSpanType& t)
        : m_ts(t)
    { /* ... */
    }

    static constexpr TimeSpan FromNanoSeconds(s64 ns) { return TimeSpanType::FromNanoSeconds(ns); }
    static constexpr TimeSpan FromMicroSeconds(s64 ms) { return TimeSpanType::FromMicroSeconds(ms); }
    static constexpr TimeSpan FromMilliSeconds(s64 ms) { return TimeSpanType::FromMilliSeconds(ms); }
    static constexpr TimeSpan FromSeconds(s64 s) { return TimeSpanType::FromSeconds(s); }
    static constexpr TimeSpan FromMinutes(s64 m) { return TimeSpanType::FromMinutes(m); }
    static constexpr TimeSpan FromHours(s64 h) { return TimeSpanType::FromHours(h); }
    static constexpr TimeSpan FromDays(s64 d) { return TimeSpanType::FromDays(d); }

    constexpr s64 GetNanoSeconds() const { return m_ts.GetNanoSeconds(); }
    constexpr s64 GetMicroSeconds() const { return m_ts.GetMicroSeconds(); }
    constexpr s64 GetMilliSeconds() const { return m_ts.GetMilliSeconds(); }
    constexpr s64 GetSeconds() const { return m_ts.GetSeconds(); }
    constexpr s64 GetMinutes() const { return m_ts.GetMinutes(); }
    constexpr s64 GetHours() const { return m_ts.GetHours(); }
    constexpr s64 GetDays() const { return m_ts.GetDays(); }

    constexpr friend bool operator==(const TimeSpan& lhs, const TimeSpan& rhs)
    {
        return lhs.m_ts == rhs.m_ts;
    }
    constexpr friend bool operator!=(const TimeSpan& lhs, const TimeSpan& rhs)
    {
        return lhs.m_ts != rhs.m_ts;
    }
    constexpr friend bool operator<=(const TimeSpan& lhs, const TimeSpan& rhs)
    {
        return lhs.m_ts <= rhs.m_ts;
    }
    constexpr friend bool operator>=(const TimeSpan& lhs, const TimeSpan& rhs)
    {
        return lhs.m_ts >= rhs.m_ts;
    }
    constexpr friend bool operator<(const TimeSpan& lhs, const TimeSpan& rhs)
    {
        return lhs.m_ts < rhs.m_ts;
    }
    constexpr friend bool operator>(const TimeSpan& lhs, const TimeSpan& rhs)
    {
        return lhs.m_ts > rhs.m_ts;
    }

    constexpr TimeSpan& operator+=(const TimeSpan& rhs)
    {
        m_ts += rhs.m_ts;
        return *this;
    }
    constexpr TimeSpan& operator-=(const TimeSpan& rhs)
    {
        m_ts -= rhs.m_ts;
        return *this;
    }

    constexpr friend TimeSpan operator+(const TimeSpan& lhs, const TimeSpan& rhs)
    {
        TimeSpan r(lhs);
        return r += rhs;
    }
    constexpr friend TimeSpan operator-(const TimeSpan& lhs, const TimeSpan& rhs)
    {
        TimeSpan r(lhs);
        return r -= rhs;
    }

    constexpr operator TimeSpanType() const { return m_ts; }
};

namespace time {

    Result Initialize();
    bool IsInitialized();

    struct CalendarTime {
        s16 year;
        s8 month;
        s8 day;
        s8 hour;
        s8 minute;
        s8 second;
    };

    enum DayOfTheWeek { Sunday,
        Monday,
        Tuesday,
        Wednesday,
        Thursday,
        Friday,
        Saturday };

    struct TimeZone {
        char standardTimeName[0x8];
        bool _9; // daylight savings or something?
        s32 utcOffset; // in seconds
    };

    struct CalendarAdditionalInfo {
        nn::time::DayOfTheWeek dayOfTheWeek;
        s32 dayofYear;
        nn::time::TimeZone timeZone;
    };

    struct PosixTime {
        u64 time;
    };

    class StandardUserSystemClock {
    public:
        static Result GetCurrentTime(nn::time::PosixTime*);
    };

    struct TimeZoneRule; // shrug

    Result ToCalendarTime(nn::time::CalendarTime*, nn::time::CalendarAdditionalInfo*,
        nn::time::PosixTime const&);
    Result ToCalendarTime(nn::time::CalendarTime*, nn::time::CalendarAdditionalInfo*,
        nn::time::PosixTime const&, nn::time::TimeZoneRule const&);
    Result ToPosixTime(int*, PosixTime*, int, const CalendarTime&);
    CalendarTime ToCalendarTimeInUtc(const PosixTime&);
    PosixTime ToPosixTimeFromUtc(const CalendarTime&);
} // namespace time
} // namespace nn
