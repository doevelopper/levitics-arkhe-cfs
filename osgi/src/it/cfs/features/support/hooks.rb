#The following example will cause scenarios tagged with @fast to fail if the execution takes longer than 0.5 second

#Around('@fast') do |scenario, block|
#  Timeout.timeout(0.5) do
#    block.call
#  end
#end

#Before do
  # Do something before each scenario.
#end

#Before do |scenario|
  # The +scenario+ argument is optional, but if you use it, you can get the title,
  # description, or name (title + description) of the scenario that is about to be
  # executed.
  Rails.logger.debug "Starting scenario: #{scenario.title}"
#end

#AfterStep do |scenario|
  # Do something after each step.
#end

#Before('@cucumis, @sativus') do
  # This will only run before scenarios tagged
  # with @cucumis OR @sativus.
#end

#Before('@cucumis', '~@sativus') do
  # This will only run before scenarios tagged
  # with @cucumis AND NOT @sativus.
#end

#Before('@cucumis, @sativus', '@aqua') do
  # This will only run before scenarios tagged
  # with (@cucumis OR @sativus) AND @aqua 
#end

#AfterStep('@cucumis', '@sativus') do
  # This will only run after steps within scenarios tagged
  # with @cucumis AND @sativus.
#end


#Before do
#  require 'fileutils'
#  featuresTmpSpace = ENV["TMP_DIR"]
#  FileUtils.rm_rf(featuresTmpSpace) if Dir.exists?(featuresTmpSpace)
#  FileUtils.mkdir(featuresTmpSpace)
#  FileUtils.touch("#{featuresTmpSpace}/cycle.log")
#end

#After do
#  # for when there are no scenarios
#  if @steps_out
#    begin
#      Process.kill :SIGKILL, @steps_out.pid # :SIGTERM not supported on Windows
#      Process.wait @steps_out.pid
#    rescue Errno::ESRCH  # exited already
#    rescue Errno::ECHILD # killed before wait call
#    end
#  end
#end