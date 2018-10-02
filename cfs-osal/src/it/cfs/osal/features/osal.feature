# Rel. 0.2 MP & MM 27/11/2012 
# Project Test
# file First.feature
# Brief descriptive text
#
Feature: Device startup
     To be able to use the system... bla bla bla
         and then... bla bla
     I must... bla bla bla

    @beforeEveryScenario    
          Background:
                Given   the device is installed in the right place
                  And   is connected to the power source
                  And   is connected to the communication media
        
    @subscenario
    @success
             Scenario:  Device startup procedure completed
                 Given  User powered up the device
                  When  Device started and completed self test procedure without errors
                  Then  Ready.Led = YELLOW.ON
                   And  Device.Status = StartUp

    @subscenario
    @fail
     Scenario Outline:  Device startup procedure failed
                 Given  Device startup procedure completed
                  When  Device finished the procedure returning <error>
                  Then  Device.Led.color  = <color>
                   And  Device.Led.status = <light>
                   And  Device.Status = <status>
                   And  User switches OFF the power source switch
                   And  User repeats the device startup procedure or calls the technical service
    
        Examples: Errors
            | error        | color | light | status  |   comment or reference   |
            | NO POWER     |   -   |   -   |    -    |                          |
            | ROM CRC      |  RED  | FIXED | ROMFLT  |                          |
            | RAM          |  RED  | BLINK | RAMFLT  |                          |
            | RF           | YELL. | FIXED | RFFLT   |                          |
            | NONE RFID    | ORAN. | FIXED | RFIDFLT |                          |

#
# Here I place suggestions, observations and criticisms emerged by discussion with the team
# and with the customer and every other note should be useful to modify the scenario
# it is a temporary block that will be deleted after the modified implementation will be ready
# tested, confirmed and approved (the history is preserved by the source code version control system
#

        
    @subscenario
    @success
    Scenario: User is known
        Given User inserted the user's card in the slot
        And   the card was previously written with data for a normal user
        When  Device knows the user
        Then  Ready.Led = GREEN.ON
        And   Device.Status = Ready

    @subscenario
    @fail
    Scenario: User isn't known
        Given User inserted the user's card in the slot
        And   the card was previously written with data for a wrong user
        When  Device doesn't know the user
        Then  Ready.Led = RED.ON
#
# Here I place suggestions, observations and criticisms emerged by discussion with the team
# and with the customer and every other note should be useful to modify the scenario
# it is a temporary block that will be deleted after the modified implementation will be ready
# tested, confirmed and approved (the history is preserved by the source code version control system
#

        
    @mainscenario
    @success
    Scenario: User logon and device ready to work
        Given Device startup procedure completed
        And   User is known
        When  Device receives the 1st data string from GPS
        Then  Device updates geographic position
        And   searches for the nearest server
        And   connects to the sensor network

    @mainscenario
    @fail
    Scenario: Device not ready to work
        Given Background conditions satisfied
        When  Device startup procedure failed
        Then  Device isn't operational


    @mainscenario
    @fail
    Scenario: Device doesn't recognize the user
        Given Device startup procedure completed
        When  Device doesn't recognize the user
        Then  Device isn't operational


#
# Here I place suggestions, observations and criticisms emerged by discussion with the team
# and with the customer and every other note should be useful to modify the scenario
# it is a temporary block that will be deleted after the modified implementation will be ready
# tested, confirmed and approved (the history is preserved by the source code version control system
#

#END OF THE EXAMPLE


# This example is the result of an initial discussion where was realized only the successful @mainscenario and then it was detailed
# better with @subscenarios to translate the initial idea to executable test steps that are sufficient to
# test the real application.


# I know that there is some skepticism about this way to write BDD style testing requirements but in my personal experience it
# is very well suited in the embedded field to simply automate acceptance tests (also if it needs some improvements).
    
# As you can see it is not so simple to define a main scenario to collect every sub scenario inside.
# The best strategy I implemented instead to implement the 3 @mainscenario is to use a Scenario Outline as this: 

    @mainscenario
    Scenario Outline: Device startup 
        Given Device startup procedure completed
        When  Device startup procedure completed returns < startError >
        And   User recognition completed returns < userError >
        Then  Device.Led.color  = <color>
        And   Device.Led.status = <light>
        And   Device.Status = <status>
    
        Examples: Errors
            | startError   | userError | color | light | status  |   comment or reference   |
            | NO POWER     |     -     |   -   |   -   |    -    |                          |
            | ROM CRC      |     -     |  RED  | FIXED | ROMFLT  |                          |
            | RAM          |     -     |  RED  | BLINK | RAMFLT  |                          |
            | RF           |     -     | YELL. | FIXED | RFFLT   |                          |
            | NONE RFID    |     -     | ORAN. | FIXED | RFIDFLT |                          |
# ...
            | NONE ERROR   |  UNKNOWN  | RED   | FIXED | RFIDFLT |                          |
            | NONE ERROR   |   KNOWN   | GREEN | FIXED |  READY  |                          |

# as you can understand in this case is not possible that the system could begin to test the user if the startup failed
# but in many other situations I found it is possible so the table grows and is not so simple to maintain it.

# So I think Gherkin could support a model where a main scenario should be the result of the composition of
# some sub scenarios and sub scenarios should be seen as steps of it so that I could re assume my idea in this way:

    # MainScenario: Device startup #the same title of the feature
        # Background
        # Step(Device startup procedure, @success, @fail) #title and a scenario list with every element comma separated
        # Step(User logon, @success, @fail)
        # After

# we could identify the scenarios with a tag next to @scenario and @subscenario or we can identify them by the title
# assuming the same title and @success or @fail tags to identify the purpose of the scenario.
# In my opinion this should simplify the translation of the scenarios to executable code and could help to decompose
# scenarios in a more detailed scenarios that should be useful in some situation to produce an executable scenario
# more near to the implementation to improve the testability.


# Another thing that should be very useful is to change the meaning of Background to Before and After, so that should be possible
# to have a Before that is common to every scenario in a feature (I mean a block that should be true before every scenario) and
# a Before that should be specific for a particular scenario.
# The same concept should be used for After.
