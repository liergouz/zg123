
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit HEAD;

// ��������������
int get_family() { return 1; }

// ���������촦��
void create()
{
        set_name("����ϼ��");
        set_picid_1(6680);
        set_picid_2(6680);

        set_level(110);
        set_value(36500);
        set_max_lasting(17499);
        set("dp", 126);
        set("pp", 69);

        setup();

        set_gender(2);
        set_head_code(58);
}

// ��������ȡ����
string get_desc()
{
        return "����ϼ��";
}
