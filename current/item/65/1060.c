
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit HEAD;

// ��������������
int get_family() { return 1; }

// ���������촦��
void create()
{
        set_name("�����");
        set_picid_1(6558);
        set_picid_2(6558);

        set_level(60);
        set_value(15500);
        set_max_lasting(10299);
        set("dp", 71);
        set("pp", 39);

        setup();

        set_gender(1);
        set_head_code(44);
}

// ��������ȡ����
string get_desc()
{
        return "�����";
}
