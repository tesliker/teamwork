<?php

/**
 * @file
 * Views integration for the mydons custom module
 */

/**
 * Implements hook_views_data()
 *
 */
function teamwork_views_data() {

 $table = array(
    'teamwork_tasks' => array(  // teamwork_tasks table
       'table' => array(
          'group' => 'Teamwork',
             'base' => array(
               'field' => 'id',  //Primary key
               'title' => 'Teamwork Tasks',
               'help' => 'Teamwork database table'
            )
        ),
     //Description of mydons_custom_id
        'id' => array(  
           'title' => t('Id'),
           'help' => t('Teamwork task  Id field'),
           // is mydons_custom_id field sortable TRUE
           'field' => array(
              'click sortable' => TRUE,  
            ),
      //Filter handler for filtering records by mydons_custom_id     
           'filter' => array(
               'handler' => 'views_handler_filter_numeric'   
            ),  

           'sort' => array(
              'handler' => 'views_handler_sort'       
           )
         ),
      //Description of mydons_custom_title field
        'project_name' => array(      
           'title' => t('Project'),
           'help' => t('Teamwork Project Name Field'),
           'field' => array(
              'click sortable' => TRUE,
           ),
           'filter' => array(
              'handler' => 'views_handler_filter_string'
           ),

           'sort' => array(
              'handler' => 'views_handler_sort'
           )
        ),
     //Description of mydons_custom_body field
       'content' => array(           
           'title' => t('Content'),
           'help' => t('Teamwork Task Content'),
           'field' => array(
                'click sortable' => TRUE,
             ),
           'filter' => array(
                 'handler' => 'views_handler_filter_string'
             ),
          'sort' => array(
             'handler' => 'views_handler_sort'
          )
        ),
        'comments_count' => array(  
           'title' => t('Comments'),
           'help' => t('Comments Count'),
           'field' => array(
              'click sortable' => TRUE,  
            ),   
           'filter' => array(
               'handler' => 'views_handler_filter_numeric'   
            ),  

           'sort' => array(
              'handler' => 'views_handler_sort'       
           )
         ),
       'description' => array(           
           'title' => t('Description'),
           'help' => t('Task Description'),
           'field' => array(
                'click sortable' => TRUE,
             ),
           'filter' => array(
                 'handler' => 'views_handler_filter_string'
             ),
          'sort' => array(
             'handler' => 'views_handler_sort'
          )
        ),
        'order' => array(  
           'title' => t('Order'),
           'help' => t('Order'),
           'field' => array(
              'click sortable' => TRUE,  
            ),   
           'filter' => array(
               'handler' => 'views_handler_filter_numeric'   
            ),  

           'sort' => array(
              'handler' => 'views_handler_sort'       
           )
         ),
       'todo_list_name' => array(           
           'title' => t('Todo List'),
           'help' => t('Todo List Name'),
           'field' => array(
                'click sortable' => TRUE,
             ),
           'filter' => array(
                 'handler' => 'views_handler_filter_string'
             ),
          'sort' => array(
             'handler' => 'views_handler_sort'
          )
        ),
       'status' => array(           
           'title' => t('Status'),
           'help' => t('Status'),
           'field' => array(
                'click sortable' => TRUE,
             ),
           'filter' => array(
                 'handler' => 'views_handler_filter_string'
             ),
          'sort' => array(
             'handler' => 'views_handler_sort'
          )
        ),
        'company_name' => array(      
           'title' => t('Company'),
           'help' => t('Company Name'),
           'field' => array(
              'click sortable' => TRUE,
           ),
           'filter' => array(
              'handler' => 'views_handler_filter_string'
           ),

           'sort' => array(
              'handler' => 'views_handler_sort'
           )
        ),
        'creator_firstname' => array(      
           'title' => t('First Name'),
           'help' => t('Creator First Name'),
           'field' => array(
              'click sortable' => TRUE,
           ),
           'filter' => array(
              'handler' => 'views_handler_filter_string'
           ),

           'sort' => array(
              'handler' => 'views_handler_sort'
           )
        ),
        'creator_lastname' => array(      
           'title' => t('Last Name'),
           'help' => t('Creator Last Name'),
           'field' => array(
              'click sortable' => TRUE,
           ),
           'filter' => array(
              'handler' => 'views_handler_filter_string'
           ),

           'sort' => array(
              'handler' => 'views_handler_sort'
           )
        ),
        'completed' => array(      
           'title' => t('Completed'),
           'help' => t('Completed'),
           'field' => array(
              'click sortable' => TRUE,
           ),
           'filter' => array(
              'handler' => 'views_handler_filter_string'
           ),

           'sort' => array(
              'handler' => 'views_handler_sort'
           )
        ),
        'start_date' => array(      
           'title' => t('Start Date'),
           'help' => t('Start Date'),
           'field' => array(
              'click sortable' => TRUE,
           ),
           'filter' => array(
              'handler' => 'views_handler_filter_string'
           ),

           'sort' => array(
              'handler' => 'views_handler_sort'
           )
        ),
        'due_date' => array(      
           'title' => t('Due Date'),
           'help' => t('Due Date'),
           'field' => array(
              'click sortable' => TRUE,
           ),
           'filter' => array(
              'handler' => 'views_handler_filter_string'
           ),

           'sort' => array(
              'handler' => 'views_handler_sort'
           )
        ),
        'created_on' => array(      
           'title' => t('Created On'),
           'help' => t('Created On'),
           'field' => array(
              'click sortable' => TRUE,
           ),
           'filter' => array(
              'handler' => 'views_handler_filter_string'
           ),

           'sort' => array(
              'handler' => 'views_handler_sort'
           )
        ),
        'priority' => array(      
           'title' => t('Priority'),
           'help' => t('Priority'),
           'field' => array(
              'click sortable' => TRUE,
           ),
           'filter' => array(
              'handler' => 'views_handler_filter_string'
           ),

           'sort' => array(
              'handler' => 'views_handler_sort'
           )
        ),
        'timeIsLogged' => array(      
           'title' => t('Time is Logged'),
           'help' => t('Time is Logged'),
           'field' => array(
              'click sortable' => TRUE,
           ),
           'filter' => array(
              'handler' => 'views_handler_filter_string'
           ),

           'sort' => array(
              'handler' => 'views_handler_sort'
           )
        ),
        'responsible_party_firstname' => array(      
           'title' => t('Responsible Party First Name'),
           'help' => t('Responsible Party First Name'),
           'field' => array(
              'click sortable' => TRUE,
           ),
           'filter' => array(
              'handler' => 'views_handler_filter_string'
           ),

           'sort' => array(
              'handler' => 'views_handler_sort'
           )
        ),
        'responsible_party_lastname' => array(      
           'title' => t('Responsible Party Last Name'),
           'help' => t('Responsible Party Last Name'),
           'field' => array(
              'click sortable' => TRUE,
           ),
           'filter' => array(
              'handler' => 'views_handler_filter_string'
           ),

           'sort' => array(
              'handler' => 'views_handler_sort'
           )
        ),
      )
    );
    return $table;
}