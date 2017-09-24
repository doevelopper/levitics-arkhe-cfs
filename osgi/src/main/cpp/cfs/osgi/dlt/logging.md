I generally subscribe to the following convention:

    Trace - Only when I would be "tracing" the code and trying to find one part of a function specifically.
    Debug - Information that is diagnostically helpful to people more than just developers (IT, sysadmins, etc.).
    Info - Generally useful information to log (service start/stop, configuration assumptions, etc). Info I want to always have available but usually don't care about under normal circumstances. This is my out-of-the-box config level.
    Warn - Anything that can potentially cause application oddities, but for which I am automatically recovering. (Such as switching from a primary to backup server, retrying an operation, missing secondary data, etc.)
    Error - Any error which is fatal to the operation, but not the service or application (can't open a required file, missing data, etc.). These errors will force user (administrator, or direct user) intervention. These are usually reserved (in my apps) for incorrect connection strings, missing services, etc.
    Fatal - Any error that is forcing a shutdown of the service or application to prevent data loss (or further data loss). I reserve these only for the most heinous errors and situations where there is guaranteed to have been data corruption or loss


Apache log4j: §1, §2

    FATAL:

        [v1.2: ..] very severe error events that will presumably lead the application to abort.

        [v2.0: ..] severe error that will prevent the application from continuing.

    ERROR:

        [v1.2: ..] error events that might still allow the application to continue running.

        [v2.0: ..] error in the application, possibly recoverable.

    WARN:

        [v1.2: ..] potentially harmful situations.

        [v2.0: ..] event that might possible [sic] lead to an error.

    INFO:

        [v1.2: ..] informational messages that highlight the progress of the application at coarse-grained level.

        [v2.0: ..] event for informational purposes.

    DEBUG:

        [v1.2: ..] fine-grained informational events that are most useful to debug an application.

        [v2.0: ..] general debugging event.

    TRACE:

        [v1.2: ..] finer-grained informational events than the DEBUG.

        [v2.0: ..] fine-grained debug message, typically capturing the flow through the applicatio