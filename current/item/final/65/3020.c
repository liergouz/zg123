
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit HEAD;

// ��������������
int get_family() { return 3; }

// ��������Ʒ���
int get_fin_type() { return 1208; }

// ���������촦��
void create()
{
        set_name("ɳ����");
        set_picid_1(6678);
        set_picid_2(6678);

        set_level(20);
        set_value(2000);
        set_max_lasting(8899);
        set("ap", 0);
        set("dp", 40);
        set("cp", 0);
        set("pp", 15);
        set("sp", 0);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "ɳ����";
}
