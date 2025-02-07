inherit OFFICER;
inherit "/inh/std/box";

// ���������촦��
void create()
{
        set_name("���ϵı���");
        set("time", 1);
        set("level", 5);
        set("reset_time", 3600);
        setup();
}

void drop_item(object me)
{
	int i, size, p, cash, amount, total, count;
	string file, result;
	object item, *team;
	size = 1 + random(3);
	result = "";
	for (i=0;i<size;i++)
	{
		p = random(10000);
		amount = 0;
		if( p < 4010)		// ��Ǯ
		{
			cash = 5000+random(200);
			me->add_cash(cash);
			if (strlen(result)==0)
				result += sprintf("%d��", cash);
			else
				result += sprintf("��%d��", cash);
			continue;
		} 
		if( p < 4060)		// ����
		{
                        switch( random(3) )
                        {
                       case 0 : file = WEAPON_FILE->get_weapon_file_2(100);  break;
                       case 1 : file = WEAPON_FILE->get_weapon_file_2(110);  break;
                       case 2 : file = WEAPON_FILE->get_weapon_file_2(120);  break;
                	}
                }
                else	
		if( p < 4110)		// ����
		{
                        switch( random(3) )
                        {
                       case 0 : file = ARMOR_FILE->get_armor_file_2(100);  break;
                       case 1 : file = ARMOR_FILE->get_armor_file_2(110);  break;
                       case 2 : file = ARMOR_FILE->get_armor_file_2(120);  break;
                	}
		}
		else                            
		if( p < 5110)		// �����м��Ʒ
		{
                        switch( random(2) )
                        {
                       case 0 : file = "/item/final/16/1612";  break;
                       case 1 : file = "/item/final/16/1626";  break;
                	}
                }		
                else   	
                if( p < 6110)		// ��ʯ
                {
                        switch( random(3) )
                        {
                       case 0 : file = "/item/stuff/0004";  break;
                       case 1 : file = "/item/stuff/0007";  break;
                       case 2 : file = "/item/stuff/0005";  break;
                	}                	
                }	
                else   	
                if( p < 6910)		// ʳ��
                {
                        switch( random(3) )
                        {
                       case 0 : file = "/item/stuff/0176";  break;
                       case 1 : file = "/item/stuff/0146";  break;
                       case 2 : file = "/item/stuff/0154";  break;
                	}               	
                }                 
                else   	
                if( p < 7710)		// ��ҩ��Դ
                {
                        switch( random(3) )
                        {
                       case 0 : file = "/item/stuff/0127";  break;
                       case 1 : file = "/item/stuff/0128";  break;
                       case 2 : file = "/item/stuff/0130";  break;
                	}                	
                }      
                else   	
                if( p < 8310)		// ��Ƕ��Դ
                {
                        switch( random(5) )
                        {
                       case 0 : file = "/item/stuff/0095";  break;
                       case 1 : file = "/item/stuff/0097";  break;
                       case 2 : file = "/item/stuff/0098";  break;
                       case 3 : file = "/item/stuff/0104";  break;
                       case 4 : file = "/item/stuff/0105";  break;
                	}                	
                }      
                else   	
                if( p < 8610)		// ��ʯ��
                {
                        switch( random(2) )
                        {
                       case 0 : file = "/item/89/8994";  break;
                       case 1 : file = "/item/89/8995";  break;
                	}                	
                }       
                else   	
                if( p < 9510)		// �÷�
                {
                        switch( random(2) )
                        {
                       case 0 : file = "/item/stuff/0052";  break;
                       case 1 : file = "/item/stuff/0054";  break;
                	}  
                }     
                else   	
                if( p < 9735)		// Ѫҩ
                {
                        file = "/item/91/9120"; 
                        amount = 4;

        	}     
                else   	
                if( p < 9960)		// ��ҩ
                {
                        file = "/item/91/9121"; 
                        amount = 4;

        	}      
                else   	
                if( p < 9970)		// �䷽
                {
                        file = "/quest/product2"->get_random_level_product(100, 120); 

        	}              
                else 
                	file = "/quest/book"->get_book_file();   
                if( load_object(file))
                {
                	
                        item = new(file);
                        if (amount>0) item->set_amount(amount);
                        item->set_user_id(me->get_id());
                        if (item->get_equip_type()) ITEM_EQUIP_D->init_equip_prop_1(item);
                        if (USER_INVENTORY_D->can_carry(me, item)==0)
                        {
                        	tell_user(me, "�����ϵĶ���̫���ˡ�");
                        	destruct(item);
                        	continue;
                        }
			if( item->get_max_combined()>1 )
			{
				if (amount<=0) amount = 1;
				total = amount;	
				count = USER_INVENTORY_D->carry_combined_item(me, item, total);
				if (result=="") result = item->get_name();
				else result += sprintf("��%s", item->get_name());
		                if( count > 0 && item->set_amount(count) )
		                {      
		                	        	
		                        if( p = item->move(me, -1) )
		                        {
		                                item->add_to_user(p);
		                        }
		                        
		                }
		                else    
		                {
		                	item->add_amount( -total );					
		                }  
			}
			else
			{
				if( p = item->move(me, -1) )
		                {
		                	if (result=="") result = item->get_name();
		                        else result += sprintf("��%s", item->get_name());
		                        item->add_to_user(p);		                        
		                }
		                else
		                {
		                	destruct(item);
		                }
			}    
						                  
                }     
	}	
	send_user(me, "%c%s", ';', "����������õ��ˣ�" + result +"��");
	team = me->get_team();
	size = sizeof(team);
	if (size>0)
	{
		for (i=0;i<size;i++)
		{
			if (team[i]->get_number()!=me->get_number()) send_user(team[i], "%c%s", ';', me->get_name()+"��������õ��ˣ�" + result +"��");
		}
	}
}
