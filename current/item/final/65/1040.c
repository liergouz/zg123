
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit HEAD;

// ��������������
int get_family() { return 1; }

// ��������Ʒ���
int get_fin_type() { return 1249; }

// ���������촦��
void create()
{
        set_name("�����");
        set_picid_1(6560);
        set_picid_2(6560);

        set_level(40);
        set_value(4000);
        set_max_lasting(9899);
        set("ap", 0);
        set("dp", 75);
        set("cp", 0);
        set("pp", 30);
        set("sp", 0);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "�����";
}
